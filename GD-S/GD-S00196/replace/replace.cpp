#include<bits/stdc++.h>
using namespace std;
typedef long long ll;//不开ll见祖宗 
int n,m,q,c[200005],tot;
string s[200005],ss[200005];
vector<int>f[200005],ff[200005];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);//freopen注释最后删掉，测了大样例改成正确格式就不要动了 
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i]>>ss[i];
	for(int l=1;l<=n;l++){
		f[l].push_back(0),ff[l].push_back(0);
		int nn=s[l].size();
		for(int i=1,j=0;i<nn;i++){
			while(j>0&&s[l][j]!=s[l][i])j=f[l][j-1];
			if(s[l][j]==s[l][i])j++;
			f[l].push_back(j);
		}
		for(int i=1,j=0;i<nn;i++){
			while(j>0&&ss[l][j]!=ss[l][i])j=ff[l][j-1];
			if(ss[l][j]==ss[l][i])j++;
			ff[l].push_back(j);
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int x:ff[i])cout<<x<<' ';
//		cout<<endl;
//	}
	while(q--){
		string t,tt;
		cin>>t>>tt;
		m=t.size();
		if(m!=tt.size()){
			cout<<0<<'\n';
			continue;
		}
		int l1=0,r1=m-1;//闭区间
		while(t[l1]==tt[l1])l1++;
		while(t[r1]==tt[r1])r1--;
		int cnt=0;
		for(int l=1;l<=n;l++){
			tot=0;
			int nn=s[l].size();
			if(m<nn)continue;
			int sh=min(l1+nn+1,m-1);
			for(int i=0,j=0;i<=sh;i++){
				while(j>0&&s[l][j]!=t[i])j=f[l][j-1];
				if(s[l][j]==t[i])j++;
				if(j==nn&&i>=r1&&i-nn+1<=l1)c[++tot]=i+1,j=f[l][j-1];
			}
			if(tot==0)continue;
//			for(int i=1;i<=tot;i++)cout<<c[i]<<' '; 
//			cout<<"lst"<<'\n';
			for(int i=0,j=0;i<=sh;i++){
				while(j>0&&ss[l][j]!=tt[i])j=ff[l][j-1];
				if(ss[l][j]==tt[i])j++;
				if(j==nn&&i>=r1&&i-nn+1<=l1){
//					cout<<i+1<<'\n';
					int idx=lower_bound(c+1,c+1+tot,i+1)-c;
					if(idx<=tot&&c[idx]==i+1)cnt++;
					j=ff[l][j-1];
				}
			}
		}
		cout<<cnt<<'\n'; 
	}
	return 0;
}
