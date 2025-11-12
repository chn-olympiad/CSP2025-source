#include<bits/stdc++.h>
using namespace std;
int X(int a,int b)
{
	int i,j;
	i=a&b;
	j=a|b;
	return j-i; 
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,x=-1,o=0;
	cin>>n>>k;
	vector<int> a;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		a.push_back(t);
	}
	for(int i=0;i<a.size();i++)
	{
		for(int j=i;j<a.size();j++)
		{
			if(x==-1)
			{
				x=a[j];
			}
			else
			{
				x=X(x,a[j]);
			}
			if(x==k)
			{
				o++;
				i=j; 
				break;
			}
		}
		x=-1; 
	} 
	cout<<o;
	return 0;
}
