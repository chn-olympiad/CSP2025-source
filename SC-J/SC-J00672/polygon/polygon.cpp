#include<bits/stdc++.h>
using namespace std;
int a[50000],b,c;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,k;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c=c+a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(c>a[n]*2)cout<<1;
		else cout<<0;
		return 0; 
	}
	else{c=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					if(i==j||i==z||j==z){
						
					}
					else{
						if((a[j]<a[i]+a[z])||(a[i]<a[j]+a[z])||(a[z]<a[i]+a[j])){
						
							if(a[j]+a[i]+a[z]>a[z]*2){
								c++;
							}
						}
					} 
				} 
			}
		}
	}
	cout<<c;
	return 0;
}