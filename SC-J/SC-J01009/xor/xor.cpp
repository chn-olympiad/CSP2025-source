#include<bits/stdc++.h>
using namespace std;
const int N =5e5+10;
int n,k,a[N],ans=0;

void d(int l,int r,int sum)
{
	if(sum==k)
	{
		ans++;
		return;
	} 
	for(int i=l;i<=n;i++)
	{
		bool x=a[i],y=sum;
		sum+=x^y;
	}
}
int main()
{
//注意freopen!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	d(1,n,0);
	cout<<ans;
	return 0;
 } 