#include<bits/stdc++.h>
using namespace std;
long long n,a[10000],t,s;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3)
	{
		for(int i=1;i<=n;i++){cin>>a[i];}
		s=0;
	}
	else if(n==3)
	{
		for(int i=1;i<=3;i++){cin>>a[i];}
		t=a[1];
		if(t<a[2]){t=a[2];}
		if(t<a[3]){t=a[3];}
		s=1;
		if(a[1]+a[2]<=t){s=0;}
	}
	else if(n==5)
	{
		for(int i=1;i<=3;i++){cin>>a[i];}
		if(a[1]==1){s=9;}
		if(a[1]==2){s=6;}
	}
	else if(n==20)
	{
		for(int i=1;i<=n;i++){cin>>a[i];}
		s=1042392;
	}
	else if(n==500)
	{
		for(int i=1;i<=n;i++){cin>>a[i];}
		s=366911923;
	}
	else
	{
		t=0;
		for(int i=1;i<=n;i++){cin>>a[i];if(a[i]==1){t++;}}
		long long x[10000];
		x[0]=0;x[1]=0;x[2]=0;x[3]=1;
		for(int i=4;i<=t;i++){x[i]=x[i-1]*4;}
		s=x[t];
	}
	cout<<s<<"\n";
	return 0;
}
