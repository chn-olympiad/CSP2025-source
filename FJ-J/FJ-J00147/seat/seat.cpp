#include<bits/stdc++.h>
using namespace std;
int a[110],b[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int t=n*m;
	for(int i=0;i<t;i++)
	{
		cin>>a[i];
	}
	int temp=a[0];
	for(int i=0;i<t;i++)
	{
		b[a[i]]=1;
	}
	int cnt=0;
	for(int i=100;i>=0;i--)
	{
		if(b[i])
		{
			a[cnt]=i;
			cnt++;
		}
	}
	for(int i=0;i<t;i++)
	{
		if(a[i]==temp)
		{
			temp=i;
			break;
		}
	}
	int t1,t2;
	t1=temp/n+1;
	t2=temp%n+1;
	if(t1%2==0)t2=n-t2+1;
	cout<<t1<<' '<<t2;
	return 0;
}
