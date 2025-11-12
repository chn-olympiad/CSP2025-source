#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,num,ans=0;
	cin>>n>>m;
	int a[n*m],a1;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	a1=a[0];
	for(int i=0;i<n*m;i++){
		for(int k=i;k<n*m;k++){
			if(a[i]<a[k]){
				num=a[k];
				a[k]=a[i];
				a[i]=num;
			}
		}
	}
	for(int i=1;i<n*m;i++){
		if(a1==a[i]){
			ans=i+1;
			break;
		}
	}
	if(ans%n==0){
		if(ans/n%2!=0){
			if(ans%m==0){
				cout<<ans/m<<" "<<n;
			}else{
				cout<<ans/m+1<<" "<<n;
			}
		}else if(ans/n%2==0){
			if(ans%m==0){
				cout<<ans/m<<" "<<1;
			}else{
				cout<<ans/m+1<<" "<<1;
			}
		}
	}else if(ans%n!=0){
		if(ans/n%2!=0){
			if(ans%m==0){
				cout<<ans/m<<" "<<n-ans%n;
			}else{
				cout<<ans/m+1<<" "<<n-ans%n;
			}
		}else if(ans/n%2==0){
			if(ans%m==0){
				cout<<ans/m<<" "<<ans%n;
			}else{
				cout<<ans/m+1<<" "<<ans%n;
			}
		}
	}
    return 0;
}

