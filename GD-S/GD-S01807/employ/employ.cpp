#include<bits/stdc++.h>
using namespace std;
bool b[11];
int n,a[11],m,k[11],ans;
char c[11];
void d(int o){
	if(o>n){
		int t=0,f=0;
		for(int i=1;i<=n;i++){
			if(c[i]=='0')t++;
			else if(a[k[i]]>t) f++;
		}
		if(f>=m)ans=(ans+1)%998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			k[o]=i;
			d(o+1);
			b[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)cin>>a[i];
	d(1);
	cout<<ans;
	return 0;
}
