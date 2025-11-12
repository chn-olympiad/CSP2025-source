/*
	
*/
#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int pd3(int a,int b,int c)
{
	int maxa=max(a,b);
	maxa=max(maxa,c);
	int cnt=a+b+c;
	cnt-=maxa;
	if(cnt<=maxa)
		return 0;
	return 1;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(n==1||n==2)
		cout<<0;
	if(n==3)
	{
		if(pd3(a[0],a[1],a[2])==1)
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	else
		cout<<n-2;
	return 0;
} 
