#include<bits/stdc++.h>
using namespace std;
int a[500005];
vector< pair<int,int> >qj;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int now;
	for(int i=1;i<=n;i++)
	{
		now=0;
		for(int j=i;j<=n;j++)
		{
			now^=a[j];
			if(now==k){
				qj.push_back(make_pair(i,j));
			}
		}
	}
//	for(auto it:qj)
//	{
//		cout<<it.first<<" "<<it.second<<endl; 
//	}
	int l=n+1;
	int ans=0;
	for(int i=qj.size()-1;i>=0;i--)
	{
		if(qj[i].second<l){
			ans++;
			l=qj[i].first;
		}
	}
	cout<<ans;
	return 0;
}

