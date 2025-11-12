
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	
	freopen("polygin.in","R",stdin);
	freopen("polygon.out","W",stdout);
	int n,a[5005];
	long long count;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int x=j+1;x<n;x++){
				if(a[i]>a[j]){
					if(a[i]>a[x]){
						if(a[x]+a[j]+a[i]>2*a[i]){
							count++;
							count=count%998244353;
						}
						
					}
				}
				else{
					if(a[j]>a[x]){
						if(a[x]+a[j]+a[i]>2*a[j]){
							count++;
							count=count%998244353;
					}
					else{
						if(a[x]+a[j]+a[i]>2*a[x]){
							count++;
							count=count%998244353;
						}
					}
					}
				}
			}
		}
	}
	cout<<count;
	return 0;
}
