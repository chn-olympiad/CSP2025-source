#include<bits/stdc++.h>
using namespace std;
int const N=1005;
int n,m,head,a[N],s[N][N];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n*m;i++)
  cin>>a[i];
  head=a[1];
  sort(a+1,a+n*m+1,cmp);
  for(int i=1;i<=n;i++)
  {
  	int tot=0;
    if(i%2==1) for(int j=(i-1)*m+1;j<=i*m;j++) s[i][++tot]=a[j];
    else for(int ij=m*i;ij>=(i-1)*m+1;ij--) s[i][++tot]=a[ij];
  }
  for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
  {
  	if(head==s[i][j])
  	{
  		cout<<i<<" "<<j;
  		return 0;
	}
  }
  return 0;
}

