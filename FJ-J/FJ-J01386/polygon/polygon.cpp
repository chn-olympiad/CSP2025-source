#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0;
	cin>>n;
	if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		if(a+b>c&&a+c>b&&b+c>a){
			cout<<"1";
		}else{
			cout<<"0";
		}
		return 0;
	}
	int a[5005],b[5005],c[5005]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
		c[a[i]]++;
	}
	for(int i=3;i<=n;i++){
		if(b[i]-a[i]*2==1){
			sum++;
		}else if(a[i]*2<b[i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
