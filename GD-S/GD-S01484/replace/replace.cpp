#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define endl '\n'
using namespace std;
const int BUF=1<<20;
char buf[BUF],*p1=buf,*p2=buf;
inline char gc(){
	if(p1==p2)p2=(p1=buf)+fread(buf,1,BUF,stdin);
	return p1==p2?EOF:*p1++;
}
template<class T=int>T read(T&&x=0){
	int f=1;
	x=0;
	char ch=gc();
	while(!isdigit(ch))f-=(ch=='-')<<1,ch=gc();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=gc();
	return x;
}
const int N=2e5+5,LEN=5e6+5;
const ull bse=3413;
ull qpow(ull a,int b){
	ull res=1;
	while(b){
		if(b&1)res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
string s[N][2],t[N][2];
vector<ull>hsh[N][2],hth[N][2];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)for(int j=0;j<2;j++)cin>>s[i][j];
	for(int i=1;i<=q;i++)for(int j=0;j<2;j++)cin>>t[i][j];
	for(int i=1;i<=n;i++)for(int j=0;j<2;j++){
		hsh[i][j].resize(s[i][j].size());
		hsh[i][j][0]=s[i][j][0]-'a';
		for(int k=1;k<s[i][j].size();k++)hsh[i][j][k]=hsh[i][j][k-1]*bse+s[i][j][k]-'a';
	}
	for(int i=1;i<=q;i++)for(int j=0;j<2;j++){
		hth[i][j].resize(t[i][j].size());
		hth[i][j][0]=t[i][j][0]-'a';
		for(int k=1;k<t[i][j].size();k++)hth[i][j][k]=hth[i][j][k-1]*bse+t[i][j][k]-'a';
	}
	for(int i=1;i<=q;i++){
		int res=0;
		for(int j=0;j<t[i][0].size();j++){
			for(int k=1;k<=n;k++){
				int l=s[i][k].size();
				if(j==l-1){
					if(hsh[k][0][j]==hth[k][0][j]&&hsh[k][1][j]==hth[k][1][j])res++;
					continue;
				}
				if(j<l)continue;
				if(hsh[k][0][l-1]==hth[k][0][j]-hth[k][0][j-l]*qpow(bse,l)
					&&hsh[k][1][l-1]==hth[k][1][j]-hth[k][1][j-l]*qpow(bse,l))res++;
			}
		}
		cout<<res<<endl;
	}
}
