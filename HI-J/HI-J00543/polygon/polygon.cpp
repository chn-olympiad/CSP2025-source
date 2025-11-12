#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int n,m=1,a1[maxn],a2[maxn],k,ans,cnt,x,y;
int f[1005][1005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a1[i]);
	}
	sort(a1+1,a1+n+1);
	if(a1[n]<a1[n-1]+a1[n-2])
	{
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}

