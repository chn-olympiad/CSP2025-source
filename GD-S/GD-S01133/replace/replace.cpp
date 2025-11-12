#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10,B=233,mod=1e9+7;
int n,q;
string s[N][2],t1,t2;
ll hsh[N][2],pw[N*25];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q,pw[0]=1;
	for(int i=1;i<=5000000;i++) pw[i]=pw[i-1]*B%mod;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		hsh[i][0]=0;
		for(int j=0;j<s[i][0].size();j++)
		  hsh[i][0]=(hsh[i][0]*B%mod+(s[i][0][j]-'a'))%mod;
		hsh[i][1]=0;
		for(int j=0;j<s[i][1].size();j++) 
		  hsh[i][1]=(hsh[i][1]*B%mod+(s[i][1][j]-'a'))%mod;
	//	cout<<hsh[i][0]<<" "<<hsh[i][1]<<endl;
	}
	//cout<<endl;
	//cout<<pw[2]*('x'-'a')<<endl;
	while(q--){
		cin>>t1>>t2;
		int l=t1.size(),r=-1,ans=0;
		for(int i=0;i<t1.size();i++)
			if(t1[i]!=t2[i]) l=min(l,i),r=max(r,i);
	//	cout<<l<<" "<<r<<endl;
		for(int i=1;i<=n;i++){
			ll h1=0,h2=0;
			int siz=s[i][0].size();
			for(int j=0;j<t1.size();j++){
				h1=h1*B%mod+t1[j]-'a',h1%=mod;
				h2=h2*B%mod+t2[j]-'a',h2%=mod;
				if(j>=siz){
					h1=(h1-pw[siz]*(t1[j-siz]-'a')%mod+mod)%mod;
					h2=(h2-pw[siz]*(t2[j-siz]-'a')%mod+mod)%mod;
				}
				if(h1==hsh[i][0]&&h2==hsh[i][1]&&j-siz+1<=l&&r<=j) ans++;
				//cout<<j<<" "<<h1<<" "<<h2<<endl;
			}
	//		cout<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
