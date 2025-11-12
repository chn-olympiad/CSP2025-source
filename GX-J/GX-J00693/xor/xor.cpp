#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int n,k,b,cnt=0;
bool a[110];

bool xo(bool a,bool b)
{
	if(a==b)return 0;
	else return 1;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	for(int i=0;i<n-1;i++)
	{
		b=a[i];
		for(int j=i+1;j<n;j++)
		{
			if(xo(b,a[j])==k){cnt++;i=j+1;}
			else b=!k;

		}
	}
	if(a[n-1]==k)cnt++;
	cout<<cnt;

	return 0;
}
