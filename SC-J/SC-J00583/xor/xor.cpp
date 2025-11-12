#include<bits/stdc++.h> 
using namespace std;
int n,k;
const int N=5e5+1000;
int arr[N];
int sum=0;
int ans=0;
int yihuo(int x,int y)
{
	if(x==y&&y==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum=arr[i];
		for(int j=i;j<=n;j++) 
		{
			if(sum==k)
			{
				ans++;
				break;
			}
			sum=yihuo(sum,arr[j]);
		}
	}
	cout<<ans;
	return 0;
} 
