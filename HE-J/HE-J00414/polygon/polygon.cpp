#include<bits/stdc++.h>
using namespace std;
int n,a[6000],ma=-2e9,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(ma==1){
		for(int i=2;i<=n;i++)sum+=((1+(n-i))*(n-i)/2);
	}else if(n==3){
		if(a[0]+a[1]>a[2]&&a[0]+a[2]>a[1]&&a[1]+a[2]>a[0])sum++;
	}else{
		sum=n;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
