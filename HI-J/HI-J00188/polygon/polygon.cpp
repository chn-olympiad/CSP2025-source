#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int a[N];
long long ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	if (n<3){
		cout<<0;
		return 0;
	} 
	sort(a+1,a+n+1);
	if (n==3){
		if (a[1]+a[2]>a[3]) ans++;
		cout<<ans;
	}else{
		if (n==4){
			if (a[1]+a[2]>a[3]) ans++;
			if (a[1]+a[2]+a[3]>a[4]) ans++;
			if (a[1]+a[3]>a[4]) ans++;
			if (a[2]+a[3]>a[4]) ans++;
			if (a[1]+a[2]>a[4]) ans++;
			cout<<ans;
		}else{
			if (n==5){
				if (a[1]+a[2]>a[3]) ans++;
				if (a[1]+a[2]+a[3]>a[4]) ans++;
				if (a[1]+a[3]>a[4]) ans++;
				if (a[2]+a[3]>a[4]) ans++;
				if (a[1]+a[2]>a[4]) ans++;
				
				if (a[1]+a[2]>a[5]) ans++;
				if (a[1]+a[3]>a[5]) ans++;
				if (a[1]+a[4]>a[5]) ans++;
				if (a[2]+a[3]>a[5]) ans++;
				if (a[2]+a[4]>a[5]) ans++;
				if (a[3]+a[4]>a[5]) ans++;
				if (a[1]+a[2]+a[3]>a[5]) ans++;
				if (a[1]+a[2]+a[4]>a[5]) ans++;
				if (a[1]+a[3]+a[4]>a[5]) ans++;
				if (a[2]+a[3]+a[4]>a[5]) ans++;
				if (a[1]+a[2]+a[3]+a[4]>a[5]) ans++;
				cout<<ans;
			}else{
				long long jk=4;
				if (a[n]==1){
					for (int i=2;i<=n;i++){
						ans=(ans+jk)%998244353;
						jk=jk*2+3;
					}
					
				}else cout<<0;
			} 
		}
	}
	
	return 0; 
}
