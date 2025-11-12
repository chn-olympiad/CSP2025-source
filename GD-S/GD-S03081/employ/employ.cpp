#include<bits/stdc++.h>
using namespace std;
int m,n,c[555],f[555],fail=0,succ=0,q[555];
long long ans=0;
string s;
void Bl(int I,int l){
	if(l==n){
		for(int i=1;i<=l;i++){
			if(s[q[i]]=='0'||c[q[i]]<=fail) fail++;
			else succ++;
		}
		if(succ>=m) ans=(ans+1)%998244353;
		fail=succ=0;
		return ;
	}
	f[I]=1;
	for(int i=1;i<=n;i++)
		if(!f[i]) q[l]=i,Bl(i,l+1);
	f[I]=0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s; s=" "+s;
	int pf=1;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++){
		q[1]=i; Bl(i,1);
	}
	cout<<ans;
	return 0;
}
