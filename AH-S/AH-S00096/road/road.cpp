#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005],s1[100005],s2[100005],b[100005],c[100005];

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i]>>b[i]>>c[i];
	for(int i=1;i<=k;i++) cin>>s1[i]>>s2[i];
	sort(c+1,c+m+1);
	int cmt=0;
	for(int i=1;i<n;i++) cmt+=c[i];
	cout<<cmt;
	return 0;
}

