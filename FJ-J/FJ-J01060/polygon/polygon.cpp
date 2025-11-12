#include<bits/stdc++.h>
using namespace std;
int const N=5005;
int n,sum,Max=-1,a[N];
int main()
{
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++) 
  {
  	cin>>a[i];
  	Max=max(Max,a[i]);
	sum+=a[i];
  }
  if(n<3) cout<<"0";
  if(n==3)
  {
  	sort(a+1,a+n+1);
  	if(a[1]+a[2]>a[3]) cout<<"1";
  	else cout<<"0";
  }
  if(n>3)
  {
  	if(sum<=Max*2) cout<<"0";
  	else cout<<"6";
  }
  return 0;
}

