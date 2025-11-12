#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n,imax=0;
	int s=0;//зм
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>imax)imax=a[i];
		s+=a[i];
	}
//	cout<<s<<" "<<imax<<" ";
	if(s>imax*2)cout<<1;
	else cout<<0;
}
