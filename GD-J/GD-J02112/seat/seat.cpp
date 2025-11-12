#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int n,m,r,num,a[maxn];
bool cmp(int pre,int nxt)
{
	return pre>nxt;
} 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int sum=n*m;
	cin>>a[1];
	r=a[1];
	for(int i=2;i<=sum;i++)
		cin>>a[i];
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++)
	{
		if(a[i]==r)
		{
			num=i;
			break;
		}
	}
	int x=ceil(num*1.0/n);
	cout<<x<<" ";
	if(x%2==1)
		cout<<num-(x-1)*n;
	else
		cout<<(n+1)-num+(x-1)*n;
	return 0;
}
