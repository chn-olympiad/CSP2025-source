#include<bits/stdc++.h>
using namespace std;
int n;
int a[50005];
int maxn;
int i;
int ans;
int s;
void f(int d,int cnt,int tnt)
{
	if(cnt ==i+1)
	{
		tnt+=a[d];
		cout<<tnt<<" "<<maxn<<endl;
		if(tnt > maxn*2)
		{
			
			ans++;
			return ;
		}
	}
	for(int l=d+1;l<=n+1;l++)
	{
		if(a[l]>a[d] and cnt+1!=i){
			s=maxn;
		maxn=a[l];
		}
		f(l,cnt+1,tnt+a[d]);
		maxn=s;
	}
}
int main()
{
	freopen("polygon.in","w",stdin);
	freopen("polygon.out","r",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=3;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++){
			maxn=j;
		f(j,0,0);
	}
	}
	cout<<ans/2;
	return 0;
}
