#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+10,M=5e6+10,bas=131,mod1=1e7+7,mod2=1e9+7;
int n,q,len[N],p[N];
ll hs1[N],hs2[N],h1[M],h2[M],pw1[M],pw2[M];
string s[N],t[N],d[N][2];
ll Hash1(int l,int r){
	return (h1[r]-h1[l-1]*pw1[r-l+1]%mod1+mod1)%mod1;	
}
ll Hash2(int l,int r){
	return (h2[r]-h2[l-1]*pw2[r-l+1]%mod2+mod2)%mod2;	
}
map<pair<string,string>,vector<int>>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw1[0]=pw2[0]=1;for(int i=1;i<M;i++)pw1[i]=pw1[i-1]*bas%mod1,pw2[i]=pw2[i-1]*bas%mod2;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
		string D[2];D[0]=D[1]="";p[i]=-1;
		d[i][0]=d[i][1]="";len[i]=s[i].size();
		for(int j=0;j<len[i];j++){
			hs1[i]=(hs1[i]*bas%mod1+s[i][j])%mod1;
			hs2[i]=(hs2[i]*bas%mod2+s[i][j])%mod2;
		}
		for(int j=0;j<len[i];j++)
		if(s[i][j]==t[i][j]){
			if(D[0]!="")D[0]+="#",D[1]+="#";
		}else D[0]+=s[i][j],D[1]+=t[i][j],p[i]=(p[i]!=-1?p[i]:j);
		for(int j=D[0].size()-1;j>=0;j--){
			if(D[0][j]==D[1][j]){
				if(d[i][0]!="")d[i][0]+='#',d[i][1]+='#';
			}else d[i][0]+=D[0][j],d[i][1]+=D[1][j];
		}reverse(d[i][0].begin(),d[i][0].end());
		reverse(d[i][1].begin(),d[i][1].end());
		mp[{d[i][0],d[i][1]}].push_back(i);
	}
	for(int _=1;_<=q;_++){
		string a,b,c[2],D[2];
		int m;cin>>a>>b;m=a.size();
		if(a.size()!=b.size()){
			puts("0");continue;
		}c[0]=c[1]=D[0]=D[1]="";
		for(int i=1;i<=m;i++){
			h1[i]=(h1[i-1]*bas%mod1+a[i-1])%mod1;
			h2[i]=(h2[i-1]*bas%mod2+a[i-1])%mod2;
		}
		int P=0;
		for(int i=0;i<m;i++){
			if(a[i]==b[i]){
				if(c[0]!="")c[0]+='#',c[1]+='#';
			}else c[0]+=a[i],c[1]+=b[i],P=(P?P:i+1);
		}int res=0;
		bool fl=0;
		for(int i=c[0].size()-1;i>=0;i--){
			if(c[0][i]!='#')fl=1,D[0]+=c[0][i],D[1]+=c[1][i];
			else if(fl)D[0]+='#',D[1]+='#';
		}reverse(D[0].begin(),D[0].end());
		reverse(D[1].begin(),D[1].end());
		for(auto i:mp[{D[0],D[1]}]){
			int pos=P-p[i];
			if(pos>0&&pos+len[i]-1<=m&&Hash1(pos,pos+len[i]-1)==hs1[i]&&Hash2(pos,pos+len[i]-1)==hs2[i]){
				res++;
			}
		}cout<<res<<endl;
	}
	return 0;
}
