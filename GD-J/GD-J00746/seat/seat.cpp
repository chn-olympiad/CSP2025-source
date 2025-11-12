#include <bits/stdc++.h>
using namespace std;
int n,m,num=1,flag=1,cnt=1;
int a[10001];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<=n*m;i++)
	{
		if(a[i]>a[1])
		{
			num++;
		}
	}
	int tmp=num/n;
	if(num%n!=0)
	{
		tmp++;
	}
//	cout<<tmp;
	if(num<=n)
	{
		cout<<"1"<<" "<<num;
		return 0;
	}
	if(tmp%2==0)
	{
		int i=tmp;
		int j=tmp*n-num+1;
		cout<<i<<" "<<j; 
	}
	else
	{
//		cout<<tmp<<endl<<num<<endl;
		int i=tmp;
		int j=num-tmp*(n-1);
		cout<<i<<" "<<j;
	}
	return 0;
}
