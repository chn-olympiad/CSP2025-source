#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int NR=500001;
vector<int> v[NR];
int s[NR];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,i,j,ans=0,lst=0;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		s[i]=s[i-1]^a;
		v[s[i]].push_back(i);
	}
	for(i=1;i<=n;i++)
	{
		int t=s[i]^k;
		for(j=0;j<v[t].size() && v[t][j]<=i;j++)
			if(v[t][j]>lst)
			{
				ans++;
				if(lst==0 && v[t][j]==1) ans++;
				lst=i;
			}
	}
	cout<<ans;
	return 0;
}
