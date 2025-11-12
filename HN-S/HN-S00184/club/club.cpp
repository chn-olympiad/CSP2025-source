#include<bits/stdc++.h>
using namespace std;
int a[10010];
int x[1001],y[1001],z[1001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i]>>y[i]>>z[i];
		}
		int x_=0,y_=0,z_=0;
		int sum=0;
		for(int i=1;i<=n;i++){
			int m=max(x[i],y[i]);
			if(z[i]>m)	m=z[i];
			if(m==x[i])	x_++;
			if(m==y[i])	y_++;
			if(m==z[i])	z_++;
			sum+=m;
		if(x_>n/2||y_>n/2||z_>n/2)
		{
			if(x_>n/2){
				if(n/2>y_&&n/2>z_){
					if(y[i]>=z[i])	{
					sum=sum-x[i]+y[i];
					continue;}
					else	{
					sum=sum-x[i]+z[i];
					continue;}
				}
				if(n/2>y_&&n/2<=z_)	{
				sum=sum-x[i]+y[i];
				continue;}
				else	{
				sum=sum-x[i]+z[i];
				continue;}
			}
			if(y_>n/2){
				if(n/2>x_&&n/2>z_){
					if(x[i]>=z[i])	{
					sum=sum-y[i]+x[i];
					continue;}
					else{
						sum=sum-y[i]+z[i];
						continue;}
				}
				if(n/2>x_&&n/2<=z_)	{
				sum=sum-y[i]+x[i];
				continue;}
				else{
					sum=sum-y[i]+z[i];
					continue;}
			}
			if(z_>n/2){
				if(n/2>x_&&n/2>y_){
					if(x[i]>=y[i])	{
					sum=sum-z[i]+x[i];
					continue;}
					else{
						sum=sum-z[i]+y[i];
						continue;}
				}
				if(n/2>x_&&n/2<=y_){
					sum=sum-z[i]+x[i];
					continue;}
				else{
					sum=sum-z[i]+y[i];
					continue;}
			}
		}
	}
	cout<<sum;	
	}
	return 0;
} 
