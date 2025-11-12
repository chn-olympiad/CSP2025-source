#include<bits/stdc++.h>
#define int long long
#define ALL(x) x.begin(),x.end()
using namespace std;
constexpr int N=2e5+1,S=5e6+1;
int n,q,nxt[S];
string s[N][2],a,b;
pair<int,int>posb[N];
char maxch;
int kmp(const string&s1,string&t1,const string&s2,string&t2){
	if(t1.size()-s1.size()!=t2.size()-s2.size())
		return 0;
	int res=0;
	vector<int>pos,rpos;
	for(int i=2,j=0;i<s1.size();i++){
		while(j&&s1[i]!=s1[j+1])
			j=nxt[j];
		if(s1[i]==s1[j+1])
			nxt[i]=(++j);
	}
	for(int i=1,j=0;i<t1.size();i++){
		while(j&&s1[j+1]!=t1[i])
			j=nxt[j];
		if(s1[j+1]==t1[i])
			j++;
		if(j==s1.size()-1){
			pos.push_back(i-j+1);
			j=nxt[j];
		}
	}
	for(int i=2,j=0;i<s2.size();i++){
		while(j&&s2[i]!=s2[j+1])
			j=nxt[j];
		if(s2[i]==s2[j+1])
			nxt[i]=(++j);
	}
	for(int i=1,j=0;i<t2.size();i++){
		while(j&&s2[j+1]!=t2[i])
			j=nxt[j];
		if(s2[j+1]==t2[i])
			j++;
		if(j==s2.size()-1){
			auto it=lower_bound(ALL(pos),i-j+1);
			if(it!=pos.end()&&(*it)==i-j+1)
				rpos.push_back(i-j+1);
			j=nxt[j];
		}
	}
	bool issame=1;
	for(int i=1,j=0;j<rpos.size();j++){
		while(i<rpos[j]&&issame){
			if(t1[i]!=t2[i]){
				issame=0;
				break;
			}
			i++;
		}
		if(!issame)
			rpos[j]=-1;
	}
	issame=1;
	for(int i=t1.size()-1,k=t2.size()-1,j=rpos.size()-1;j>=0;j--){
		if(rpos[j]==-1)
			continue;
		while(i>rpos[j]+s1.size()-2&&issame){
			if(t1[i]!=t2[k]){
				issame=0;
				break;
			}
			i--,k--;
		}
		if(!issame)
			rpos[j]=-1;
	}
	for(auto v:rpos)
		if(v!=-1)
			res++;
	return res;
}
signed main(){
	freopen("replace.in","r",stdin),
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		for(auto ch:s[i][0])
			maxch=max(maxch,ch);
		s[i][0]=" "+s[i][0],s[i][1]=" "+s[i][1];
	}
	if(maxch=='b'){
		for(int i=1;i<=n;i++){
			for(int j=1;j<s[i][0].size();j++)
				if(s[i][0][j]=='b'){
					posb[i].first=j;
					break;
				}
			for(int j=1;j<s[i][1].size();j++)
				if(s[i][1][j]=='b'){
					posb[i].second=j;
					break;
				}
		}
		string a,b;
		for(int x,y;q;--q){
			int res=0;
			cin>>a>>b;
			a=" "+a,b=" "+b;
			for(int j=1;j<a.size();j++)
				if(a[j]=='b'){
					x=j;
					break;
				}
			for(int j=1;j<b.size();j++)
				if(b[j]=='b'){
					y=j;
					break;
				}
			for(int i=1;i<=n;i++){
				if((int)a.size()-s[i][0].size()!=(int)b.size()-s[i][1].size()||s[i][0].size()>a.size())
					continue;
				int p=posb[i].first,q=posb[i].second;
				if(x-p!=y-q||x-p<0||x-p+s[i][0].size()-1>=a.size()||y-q+s[i][1].size()-1>=b.size())
					continue;
				res++;
			}
			cout<<res<<'\n';
		}
		return 0;
	}
	for(int res;q;--q){
		res=0;
		cin>>a>>b;
		a='@'+a,b='@'+b;
		for(int i=1;i<=n;i++)
			res+=kmp(s[i][0],a,s[i][1],b);
		cout<<res<<'\n';
	}
	return 0;
}
