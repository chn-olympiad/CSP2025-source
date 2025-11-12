#include<bits/stdc++.h>
using namespace std;
int n,m,a[501],b[501],k=0,c[501],answer[501];
string st;
long long ans=1;
const long long mod=998244353;
int main()
{
	cin>>n>>m>>st;
	for(int i=1;i<=n;i++)
	  cin>>b[i];
	for(int i=0;i<st.size();i++)
	  a[i+1]=st[i]-'0';
	sort(b+1,b+1+n);
	int tmp=0;
	for(int i=1;i<=n;i++)
	{
	  if(k>=b[n-i+1] or a[i]==0)k++;
	  else tmp++,c[i]=b[n-i+1]-k;
    }
    if(tmp<m)return cout<<0,0;
    for(int i=1;i<=500;i++)
    {
      for(int j=1;j<=n;j++)
		  if(c[j]>=i)answer[i]++;
	  if(answer[i]==0)answer[i]=1;
    }
    for(int i=1;i<=500;i++)cout<<ans;
    return 0;
}
