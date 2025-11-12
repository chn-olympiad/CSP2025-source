#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0; 
	}
	if(n==3){
		sort(a,a+n);
		if(a[0]+a[1]>a[2]){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	if(n==4){
		sort(a,a+n);
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int z=j+1;z<n;z++){
					if(a[i]+a[j]>a[z]){
						ans++;
					}
				}
			}
		}
		if(a[0]+a[1]+a[2]+a[3]>a[3]*2){
			cout<<ans+1; 
		}
		else{
			cout<<ans;
		}
		return 0;
	}
	return 0;
}
