#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int sum=0;
		int a[n]={0,0},b[n]={0,0},c[n]={0,0};
		int x1=0,x2=0,x3=0;
		for(int j=0;j<n;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
		for(int j=0;j<n;j++){
			if(a[j]>=b[j]&&a[j]>=c[j]){
				sum=sum+a[j];
				x1=x1+1;
			}else if(b[j]>=a[j]&&b[j]>=c[j]){
				sum=sum+b[j];
				x2=x2+1;
			}else if(c[j]>=a[j]&&c[j]>=b[j]){
				sum=sum+c[j];
				x3=x3+1;
			}
		}
		for(int j=0;j<n;j++){
			if(x1>n/2){
				sum=sum-a[j]+b[j]+2;
			}
			if(x2>n/2){
				sum=sum-b[j]+a[j]+1;
			}
			if(x3>n/2){
				sum=sum-c[j]+a[j]+1;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
