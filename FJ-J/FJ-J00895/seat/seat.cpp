#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<math.h>
using namespace std;
int n,m;
int a[1005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int t=a[1];
	sort(a+1,a+1+n*m,cmp);
	int k;
	for(int i=1;i<=n*m;i++){
		if(a[i]==t)
			k=i;
	}
//	cout<<k<<endl;
	int r=0,c=floor(k*1.0/n);
	r=k%m;
	if(r!=0)c++;
	else r=n;
	if(c%2==1){
		cout<<c<<' '<<r<<endl;
	}
	else{
		cout<<c<<' '<<(m-r+1)<<endl;
	}
	return 0;
}
