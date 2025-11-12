#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int n;
int a[10000000];
int num[10000000];
int ans;
int main(){	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}sort(a+1,a+1+n);
	
	int m=1;
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			for(int k=j+1;k<=n;k++){
				num[m]=a[i]+a[j]+a[k];
				if(num[m]>a[k]*2){
					ans++;
				}
				m++;
			}
		}
	}cout<<ans;
	return 0;
}
