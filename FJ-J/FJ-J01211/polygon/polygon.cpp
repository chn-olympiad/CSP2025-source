#include<bits/stdc++.h>
using namespace std;
int a[10000];
int sum=0,smm,n;
int  bfs(int x,int l)
{
	if(x==1) return a[1];
	if(x==2) return a[1]+a[2];
	for(int i=1;i<=x-1;i++)
	{
		l+=a[x-i];
		if(l>smm) sum++;
		return (l+bfs(x-i,l));
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=n;i>=3;i--)
	{
		smm=a[i]*2;
		bfs(i,a[i]);
	} 
	cout<<sum*3%998244353;
	return 0;
}
