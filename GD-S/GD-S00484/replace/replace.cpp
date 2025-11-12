#include<bits/stdc++.h>
#define bs1 1331
#define bs2 3113
#define mod1 998244853
#define mod2 1000000009
#define int long long
using namespace std;
int n,q,m,o,len[200005],fr[200005],f1[5000005],f2[5000005],tot;
array<int,7>p[200005];
string s1,s2,s[200005],ss;
array<signed,26>g;
class AC{public:
	vector<array<signed,26>>tr;
	vector<signed>f;int cnt=0;
	vector<vector<signed>>ve;
	unordered_map<int,int>mp;
	void add(){cnt++,tr.emplace_back(g),f.emplace_back(0);}
	void clear(){
		tr.clear(),tr.shrink_to_fit();
		f.clear(),f.shrink_to_fit();
		ve.clear(),ve.shrink_to_fit();
		tr.emplace_back(g),f.emplace_back(0);
	}
	void insert(int n,string&s){
		int p=0,hs1=0,hs2=0;mp[0]=0;
		for(int i=1;i<=n;i++){
			if(!tr[p][s[i]-'a'])add(),tr[p][s[i]-'a']=cnt;
			hs1=(hs1*bs1+s[i])%mod1,hs2=(hs2*bs2+s[i])%mod2;
			p=tr[p][s[i]-'a'];mp[hs1*(mod2+1)+hs2]=p;
		}
		f[p]++;
	}
	void dfs(int u){for(int i=0;i<26;i++)if(tr[u][i])f[tr[u][i]]+=f[u],dfs(tr[u][i]);}
	int query(int n,string&s){
		int ans=0,p=0;
		for(int i=1;i<=n;i++)p=tr[p][s[i]-'a'],ans+=f[p];
		return ans;
	} 
}t[200005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2,m=s1.size(),s1=" "+s1,s2=" "+s2;
		int l=1,r=m;
		while(l<=m&&s1[l]==s2[l])l++;
		if(l>m)continue;
		while(r&&s1[r]==s2[r])r--;
		int hs1=0,hs2=0,hs3=0,hs4=0,hs5=0,hs6=0;
		for(int j=l;j<=r;j++){
			hs1=(hs1*bs1+s1[j])%mod1,hs2=(hs2*bs2+s1[j])%mod2;
			hs3=(hs3*bs1+s2[j])%mod1,hs4=(hs4*bs2+s2[j])%mod2;
		}
		for(int j=l-1;j;j--)hs5=(hs5*bs1+s1[j])%mod1,hs6=(hs6*bs2+s2[j])%mod2;
		p[++o]={hs1,hs2,hs3,hs4,hs5,hs6,i},len[i]=(m-r),s[i]=" ";
		for(int j=r+1;j<=m;j++)s[i]+=s2[j];
	}
	sort(p+1,p+o+1);
	for(int i=1;i<=o;i++){
		int flag=i!=1;
		for(int j=0;j<6;j++)flag&=p[i][j]==p[i-1][j];
		if(!flag)tot++,t[tot].clear();
		fr[i]=tot,t[tot].insert(len[p[i][6]],s[p[i][6]]);
	}
	for(int i=1;i<=tot;i++)t[i].dfs(0); 
	while(q--){
		cin>>s1>>s2;tot++;
		if(s1.size()!=s2.size()){cout<<"0\n";continue;}
		m=s1.size(),s1=" "+s1,s2=" "+s2;
		int l=1,r=m;
		while(l<=m&&s1[l]==s2[l])l++;
		while(r&&s1[r]==s2[r])r--;
		int hs1=0,hs2=0,hs3=0,hs4=0,hs5=0,hs6=0,ans=0;
		for(int j=l;j<=r;j++){
			hs1=(hs1*bs1+s1[j])%mod1,hs2=(hs2*bs2+s1[j])%mod2;
			hs3=(hs3*bs1+s2[j])%mod1,hs4=(hs4*bs2+s2[j])%mod2;
		}
		f1[r]=f2[r]=0;
		for(int j=r+1;j<=m;j++)f1[j]=(f1[j-1]*bs1+s1[j])%mod1,f2[j]=(f2[j-1]*bs2+s2[j])%mod2;
		for(int j=l;j;j--){
			if(j!=l)hs5=(hs5*bs1+s1[j])%mod1,hs6=(hs6*bs2+s1[j])%mod2;
			int xx=lower_bound(p+1,p+o+1,(array<int,7>){hs1,hs2,hs3,hs4,hs5,hs6,0})-p;
			if(p[xx][0]!=hs1||p[xx][1]!=hs2||p[xx][2]!=hs3||p[xx][3]!=hs4||p[xx][4]!=hs5||p[xx][5]!=hs6)continue;
			int ll=r+1,rr=m,res=r;
			while(ll<=rr){
				int mid=ll+rr>>1;
				if(t[fr[xx]].mp.count(f1[mid]*(mod2+1)+f2[mid]))res=mid,ll=mid+1;
				else rr=mid-1;
			}
			int o=t[fr[xx]].mp[f1[res]*(mod2+1)+f2[res]];
			ans+=t[fr[xx]].f[o];
		}
		cout<<ans<<"\n";
	}
}
