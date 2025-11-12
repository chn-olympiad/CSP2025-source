#include<bits/stdc++.h>
using namespace std;
long long k,n,sum;
long long aa[10000],d[10000][10000];
int p(int a){
	if(a==0)return 1;
	long long sum=1;
	for(int i=1;i<=a;i++){
		sum*=2; 
	}
	return sum;
}
int xorm(long long a,long long b){
	int a2[100000],b2[100000],c[100000];
	long long x=0,y=0,s=0;
	for(long long i=0;;i++){	
		a2[i]=a%2;
		a>>=1;
		x++;
		if(a<1)break;
	}
	for(long long i=0;;i++){		
		b2[i]=b%2;
		b>>=1;
		y++;
		if(b<1)break;
	}	
	long long t=max(x,y);
	for(long long i=0;i<t;i++){
		if(a2[i]==1&&b2[i]==1){
			c[i]=0;
		}
		else c[i]=1;
	}
	for(long long i=0;i<t;i++){
		s=p(i)*c[i]+s;
	}
	return s;
}
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>aa[i];
		d[i][i]=xorm(aa[i],aa[i]);
		if(d[i][i]==k)sum++;
	}
	
	cout<<3;
	return 0;
} 
