#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int n,k,ans=0;
int main()
{
	scanf("%d%d",&n,&k);
	if(k==0) 
	{
		cout<<n/2;
		return 0;
	}
	for(int i=0,t;i<n;i++)
	{
		scanf("%d",&t);
		v.push_back(t);
	}
	for(int i=0,t=0;i<n;i++)
	{
		t=t xor v[i];
		if(t==k) ans++,t=0;
	}
	cout<<ans;
	return 0;
}
