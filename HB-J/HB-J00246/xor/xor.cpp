#include <bits/stdc++.h>
using namespace std;
int n,m,a[200002],ans,book[200023];
int find(int s,int e)
{
	int cnt=0;
	for(int i=s;i<=e;i++)
	{
		cnt+=book[i];
	}
	return cnt;
}
void mk(int s,int e)
{
	for(int  i=s;i<=e;i++){
		
		book[i]=1;
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==m){
			ans++;
			book[i]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int sum=a[i];
		for(int j=i+1;j<=n;j++)
		{
			sum=sum^a[j];
			if(sum==m && find(i,j)==0){
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
