#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int arr[N];
bool cmp(int a,int b)
{
	return a>b; 
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>arr[i];
	int stu=arr[1];
	sort(arr+1,arr+1+n*m,cmp);
	int tmp;
	for(int i=1;i<=n*m;i++)
	{
		if(arr[i]==stu)
		{
			tmp=i;
			break; 
		}
	}
//	cout<<tmp<<" "<<stu;
	int l=tmp/n;//在第几列 
	if(tmp%n!=0)l++;
	cout<<l<<" ";
	if(l%2==0)
	{
		if(tmp%n==0)cout<<1;
		else cout<<n-tmp%n+1;
	}
	else //在奇数列 
	{
		if(tmp%n==0)cout<<n;
		else cout<<tmp%n;
	}
}
