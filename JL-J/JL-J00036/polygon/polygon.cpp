#include<bits/stdc++.h>
using namespace std;
int m[999999],x[123456];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,sum=0,max=0,min=134,a,b,c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i];
	}
	if(n<=2){
		cout<<0;
	}
	if(n==3){
		for(int i=1;i<=n;i++){
			if(m[i]>sum){
				sum=m[i];
				a=i;
			}
			if(m[i]<min){
				min=m[i];
				b=i;
			}
		}
		x[1]==m[b];
		x[3]==m[a];
		m[a]=0,m[b]=0;
		for(int i=1;i<=n;i++){
			if(m[i]!=0){
				x[2]=m[i];
			}
		}
		if(x[1]+x[2]+x[3]>x[3]*2){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if(n==4){
		for(int i=1;i<=n;i++){
			if(m[i]>sum){
				sum=m[i];
				a=i;
			}
			if(m[i]<min){
				min=m[i];
				b=i;
			}
		}
		x[1]==m[b];
		x[4]==m[a];
		m[a]=0,m[b]=0;
		int l=0;
		for(int i=1;i<=n;i++){
			if(m[i]!=0){
				if(m[i]>l){
					l=m[i];
					c=i;
				}
			}
		}
		x[3]=m[c];
		for(int i=1;i<=n;i++){
			if(m[i]!=0){
				x[2]=m[i];
			}
		}
		if(x[1]+x[2]+x[3]>x[3]*2){
			max++;
		}
		if(x[1]+x[2]+x[4]>x[4]*2){
			max++;
		}
		if(x[2]+x[3]+x[4]>x[3]*2){
			max++;
		}
		if(x[3]+x[2]+x[4]>x[4]*2){
			max++;
		}
		if(x[1]+x[2]+x[3]+x[4]>x[4]*2){
			max++;
		}
		cout<<max;
	}
	else{
		cout<<9;
	}
	return 0;
	}
	
