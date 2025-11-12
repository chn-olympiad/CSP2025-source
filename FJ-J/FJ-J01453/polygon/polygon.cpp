#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005];
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=0;
	for(int i=3;i<n;i++){
		if(i==3){
			if(a[1]+a[2]+a[3]>2*a[3]){
				ans++;
			}
		}
	} 
	return 0;
} 
