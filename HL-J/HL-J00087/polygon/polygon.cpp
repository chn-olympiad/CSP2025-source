#include<bits/stdc++.h>
using namespace std;
int n,s;
int a[5000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int z=1;z<=n;z++){
				if(i!=j&&j!=z&&i!=z){
					if(a[i]+a[j]>a[z]&&a[i]+a[z]>a[j]&&a[j]+a[z]>a[i]){
						s++;
					}
				}
			}
		}
	}
	cout<<s/2;
	return 0;
}
