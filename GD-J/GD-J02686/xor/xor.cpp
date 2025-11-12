#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
bool book[5000001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	vector<long long> l(1);
	for(int i=1;i<=n;i++)
	{
	  int l1;
	  cin>>l1;
	  l.push_back(l1);
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
	  long long a=l[i];
	  if(a==k)
	  {
		book[i]=true;
		cnt++;
	  }
	}
	for(int i=1;i<=n-1;i++)
	  for(int j=i+1;j<=n;j++)
	  {
	  	long long a=l[i];
	  	bool z=true;
	    for(int k=i+1;k<=j;k++)
	      if(!book[k])
		    a^=l[k];
		  else
		  {
		  	z=false;
		    break;
		  }
	    if(a==k&&z)
		{
		  for(int g=i;g<=j;g++)
			book[g]=true;
		  cnt++;
	    }
	  }
	cout<<cnt;
	return 0;
}
