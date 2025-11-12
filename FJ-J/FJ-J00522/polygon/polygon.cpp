#include <bits/stdc++.h>
using namespace std;
vector<int>len;
vector<vector<long long>>DPmap;
vector<int>sum;
int main()
{
	freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	int n,tmp;
	cin>>n;
	long long answer=0;
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		len.push_back(tmp);
	}
	sort(len.begin(),len.end()+1);
	sum.push_back(len[0]);
	for(int i=1;i<n;i++)
	sum.push_back(len[i]+sum[i-1]);
	DPmap.resize(n,vector<long long>(sum[n-1]+1,0));
	DPmap[0][len[0]]=1; 
	for(int i=0;i<n;i++)
	DPmap[i][0]=1;  
	for(int i=1;i<n;i++)
	for(int j=0;j<i;j++) 
	for(int k=len[i];k<=sum[j];j++)
	DPmap[i][k]+=DPmap[j][k-len[i]];
	for(int i=2;i<n;i++)
	for(int j=len[i]+1;j<=sum[i-1];j++)
	answer+=DPmap[i-1][j];
	cout<<answer%998244353;
	return 0;
}
