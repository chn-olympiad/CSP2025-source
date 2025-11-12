#include<bits/stdc++.h>
using namespace std;
int a[5005],sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		for(int j = i;j < n;j++){
			if(a[i]+a[j]>a[j+1]){
				sum++;
			}
		}
		for(int j = i;j < n-1;j++){
			if(a[i]+a[j]+a[j+1]>a[j+2]){
				sum++;
			}
		}
		for(int j = i;j < n-2;j++){
			if(a[i]+a[j]+a[j+1]+a[j+2]>a[j+3]){
				sum++;
			}
		}
	}
	cout<<sum/2;
	return 0;
}
