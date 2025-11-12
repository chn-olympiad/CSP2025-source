#include<bits/stdc++.h>
#define mod 988244353
using namespace std;
int a,b,c,d;
long long ans;
int g[5005]; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++)cin>>g[i];
	sort(g,g+a);
	if(a<=3){
		if(a<=2){
			cout<<0;
			return 0;
		}
		else{
			if(g[0]+g[1]<=g[2]){
				cout<<0;
				return 0;
			}
			else{
				if(g[0]==g[1]==g[2]){
					cout<<3;
					return 0;
				}
				else if(g[0]==g[1]||g[1]==g[2]||g[2]==g[0]){
					cout<<2;
					return 0;
				}
				else{
					cout<<1;
					return 0;
				}
			}
		}
	}
	for(int i=3;i<=a;i++){
		for(int j=2;j<=i;j++){
			ans++;
			ans=ans%mod;
		}
	} 
	cout<<ans;
	return 0;
}
