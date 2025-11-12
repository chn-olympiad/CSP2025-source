#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
vector<pair<int,int> > tmp; 
vector<pair<int,int> > final;
int pre[N],a[N];
int n,k,cnt;
bool cmp(pair<int,int> a,pair<int,int> b)
{
	return a.second<b.second;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	pre[1]=a[1];
	for(int i=2;i<=n;i++) pre[i]=a[i]^pre[i-1];
	for(int i=1;i<=n;i++)
	 for(int j=i;j<=n;j++)
	 {
	 	if((pre[j]^pre[i-1])==k)
	 	{
	 		tmp.push_back({i,j});
	 		break;
		 }
		 
	 }
	int r=0;
	sort(tmp.begin(),tmp.end(),cmp);
	for(int i=0;i<tmp.size();i++) 
		if(tmp[i].first>r) cnt++,r=tmp[i].second;
	cout<<cnt<<endl;
	return 0;
 }
 //平方复杂度能骗多少呢qwq 
