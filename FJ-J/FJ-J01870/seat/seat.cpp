#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],r,w,s;
bool c(int a,int b)
{
	if(a>b)
	return 1;
	else
	return 0;
}
int main(){
	//*freopen("seat.in","r",stdin);
	//*freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)
		{
			r=a[i];
		}
	}
	sort(a+1,a+1+n*m,c);
	for(int i=1;i<=m*n;i++)
	{
		if(a[i]!=r)
		{
			s++;
		}
		else
		{
			s++;
			break;
		}
	}
	long long ch=s/n;
	if(s%n>0)
	{
		ch++;
	}
	cout<<ch<<" ";
	if(ch%2==1)
	{
		cout<<s-(ch-1)*n;
	}
	else
	{
		cout<<n-(s-(ch-1)*n)+1;
	}
}
