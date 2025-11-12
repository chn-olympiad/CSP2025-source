#include<bits/stdc++.h>
using namespace std;
int const N=200005;
int n,k,tot1,tot2,cnt,place=1,now=0,num,a[N],t[N];
struct node
{
   int begin;
   int end;
}s[N];
void solve1()
{
    if(k==1) cout<<n;
	if(k==0) cout<<n/2;
	if(k!=1&&k!=0) cout<<"0";
	return;
}
void solve2()
{
	if(k==0) 
	{
		for(int j=1;j<=n;j++)
		{
			if(j<n&&a[j]==1&&a[j+1]==1&&t[j]!=1) 
			{
				t[j]=1;t[j+1]=1;
				num++;
			}
			if(a[j]==0) num++;
		}
	}
	if(k==1) 
	{
		for(int j=1;j<=n;j++)
		if(a[j]==1) num++;
	}
	cout<<num;
}
void solve3()
{
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0) num++;
			else if(a[i]==a[i+1]&&t[i]!=1) 
			{
				t[i]=1;t[i+1]=1;
				num++;
			}
		}
	}
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		if(a[i]==1) num++;
	}
	if(k!=1&&k!=0)
	{
	for(int i=1;i<=n;i++)
	for(int j=i;j<=n;j++)
	{
	  int ans=0;
	  for(int ij=i;ij<=j;ij++) ans=a[ij]^ans;
	  if(ans==k) 
	  {
	  	s[++cnt].begin=i;
	  	s[cnt].end=j;
	  }
	}
    while(now<n&&place<=n)
  {
  	for(int i=place;i<=n;i++)
  	{
  	  if(s[i].begin>now) 
  	  {
  	  	now=s[i].end;
  	  	num++;
  	  	place=i+1;
  	  	break;
	  }
	}
  }
	}
  cout<<num;
  return;
}
int main()
{
  freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
  	cin>>a[i];
  	if(a[i]==1) tot1++;
  	if(a[i]==0) tot2++;
  }
  if(tot1==n) solve1();
  else if(tot1+tot2==n) solve2();
  else solve3();
  return 0;
}

