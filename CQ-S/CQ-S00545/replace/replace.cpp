#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const ull mod=50000000;
ull n,q,pp=13131,x[50000005],h[2005],l,r,f[2005],zym;
string s[1005],ss[1005],t[1005],tt[1005];
ull get1(string o){
	ull sh=0;
	for(int i=0;i<o.size();i++){
		sh=sh*pp+(ull)(o[i]);
	}
	return sh%mod;
}
inline void hash1(string o){
	for(int i=0;i<o.size();i++){
		h[i+1]=h[i]*pp+(ull)(o[i]);
	}
	return ;
}
ull power(ull o,ull u){
	ull p_x=1;
	while(u>=1){
		if((u&1)==1){
			p_x*=o;	
		}
		o*=o;
		u>>=1;
	}
	return p_x;
}
ull get2(ull l,ull r){
	return (h[r+1]-h[l]*power(2,r-l+1))%mod;
}
inline void hash2(string o){
	for(int i=0;i<o.size();i++){
		f[i+1]=f[i]*pp+(ull)(o[i]);
	}
	return ;
}
ull get3(ull l,ull r){
	return (f[r+1]-f[l]*power(2,r-l+1))%mod;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	*cin.tie(nullptr)<<fixed<<setprecision(20);
	cout.tie(nullptr)->ios_base::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>ss[i];
		x[get1(s[i])]=get1(ss[i]);
	}
	for(int i=1;i<=q;i++){
		zym=0;
		cin>>t[i]>>tt[i];
		hash1(t[i]);
		hash2(tt[i]);
		for(int j=0;j<t[i].size();j++){
			if(t[i][j]!=tt[i][j]){
				l=j;
				break;
			}
		}
		for(int j=t[i].size()-1;j>=0;j--){
			if(t[i][j]!=tt[i][j]){
				r=j;
				break;
			}
		}
		for(int j=l;j>=0;j--){
			for(int k=r;k<t[i].size();k++){
				if(x[get2(j,k)]==get3(j,k)){
					zym++;
				}
			}
		}
		cout<<zym<<'\n';
	}
	return 0;
}
