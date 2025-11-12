#include<bits/stdc++.h>
using namespace std;
long long a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,s=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<n-1;j++){
			for(int z=j+1;z<=n;z++){
				if(a[i]+a[j]+a[z]>max(max(a[i],a[j]),a[z])*2){
					s++;
				}
			}
		} 
	}
	cout<<1;
	return 0;
}
