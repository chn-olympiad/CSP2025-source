#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int max1=-1,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		for(int i=1;i<=3;i++){
			if(max1<a[i]){
				max1=a[i];
			}
		}
		if(a[1]+a[2]+a[3]>2*max1){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	for(int i=3;i<=n;i++){
		if(n>i){
			sum+=n-i+1;
		}
		else if(n==i){
			sum++;
		}
		else{
			cout<<sum;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
}
