#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum,i,b,j;
void dfs(int i,int j,int b,int sum)
{
	if(b>=n)return;if(i>=n&&b<n)dfs(i,j,b+1,sum);
	if(i>=b)dfs(i-1,j,b,sum);
	if(j>=b-i)dfs(i++,0,b,sum);
	if(a[i]+a[i+j]+a[b+i-1]>2*a[b+i-1] && i+j<b+i-1){sum++;dfs(i,j++,b,sum);b--;}
}
int main()
{freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(i=1;i<=n;i++)cin>>a[i];
i=1;b=3;
dfs(i,j,b,sum);
cout<<sum<<endl;
return 0;
}
