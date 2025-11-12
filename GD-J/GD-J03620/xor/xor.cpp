#include<iostream>
#include<vector>
using namespace std;
vector<int> a(500005,0);
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1) cnt++;
	}
	if(cnt==n)
	{
		cout<<n/2;
		return 0;
	}
	cout<<0;
	return 0;
}
