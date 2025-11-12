#include<bits/stdc++.h>
using namespace std;
int n,a[5005],s,ma,k;
long long sum;
void QAQ(int u,int c)
{
	s+=a[u];
	if(s>a[u]*2&&c>=3)
	  sum++;
	if(u==n)return ;
	for(int i=u+1;i<=n;i++)
	{
		QAQ(i,c+1);
		s-=a[i];
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
      cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n-2;i++)
  	  QAQ(i,1);
    
    cout<<sum%998244353-1;
	return 0;
 } 