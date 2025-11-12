#include<bits/stdc++.h>
using namespace std;
const int maxn=500000+10;
const int maxv=(1<<20)+10;
int n,k,ans=0,last=0,a[maxn],cnt[maxv];
vector<int> p[maxv];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k; p[0].push_back(0); cnt[0]++;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]^=a[i-1];
		if(!cnt[a[i]]) cnt[a[i]]++;
		int t=(a[i]^k);
		while(cnt[t] && cnt[t]<=(int)p[t].size() && p[t][cnt[t]-1]<last) cnt[t]++;
		if(cnt[t] && cnt[t]<=(int)p[t].size()) ans++,last=i;
		p[a[i]].push_back(i);
	}
	printf("%d\n",ans);
	return 0;
}