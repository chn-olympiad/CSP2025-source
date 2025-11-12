#include<bits/stdc++.h>
using namespace std;
int n,m;
string a;
int b[501];
int ans,sum;
int main()
{
	freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
	cin>>n>>m;
  	cin>>a;
  int x=a.length();
  for(int i=0;i<n;i++)
  {
  	cin>>b[i];
  }
  sort(b,b+n);
  for(int i=0;i<n;i++)
  {
  	if(a[i]=='0')
  	{
  		ans++;
		  if(ans>b[i])
		  {
		  	n--;
		  }
	}else{
		sum++;
	}
  }
  cout<<sum;
  return 0;
}
