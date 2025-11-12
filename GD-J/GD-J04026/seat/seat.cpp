#include<bits/stdc++.h>
using namespace std;
int a[200];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++) cin>>a[i];
	int s=a[1],f;
	sort(a+1,a+len+1);
	for(int i=len;i>=1;i--)
	{
		if(a[i]==s) f=len-i+1;
	}
	bool UD=1;
	int h=0,l=1;
	while(f/n)
	{
		if(f==n) break;
		UD=!UD;
		f-=n;
		l++;
	}
	if(UD) h=f;
	else h=n-f+1;
	cout<<l<<' '<<h;
	return 0;
}
