#include<bits/stdc++.h>
using namespace std;
int n,a[500002],qsum[500002],k,lst=1,ans;
map<int,int> mp;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	mp[0]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		qsum[i]=qsum[i-1]^a[i];
		int qwq=qsum[i]^k;
		if(mp[qwq]>=lst)
		{
			lst=i;
//			cout<<mp[qwq]<<" "<<i<<"\n";
			mp[qwq]=0;
			ans++;
		}
		mp[qsum[i]]=i;
	}
	cout<<ans;
	return 0;
}
/*
稍微有点难
我们求一个前缀和，每次将其异或上当前数，再
寻找若以此点为右端点的左端点。 
*/ 