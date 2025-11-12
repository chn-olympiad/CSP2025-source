#include<bits/stdc++.h>
using namespace std;
int n,a[5100];
long long ans;

bool istx(int len,int bg){
	if(len>bg*2){
		return 0;
	}
	return 1;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
    }
    int mx=0,k=0,t=2;
    while(n-t!=1){
		for(int i=1;i<=n-t;i++){
			for(int j=1;j<=i+t;j++){
				mx=max(a[j],mx);
				k+=a[j];
			}
			
			if(istx(k,mx)==0){
				ans++;
			}
			k=0;
			mx=0;
		}	
		if(n-t!=1){
			t++;
		}
	}
    cout<<ans<<endl;
  	return 0;
}
