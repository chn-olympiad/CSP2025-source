#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],b[N],c[N],vis[N],fh[N];
int t[N],tot,sum[N],ans;
bool cmp(int x,int y){
	return x>y;
}
void Clean(){
	sum[1]=sum[2]=sum[3]=0;
	ans=tot=0;
}
void work(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		int val=max(a[i],max(b[i],c[i]));
		if(val==a[i]){
			vis[i]=1;
			fh[i]=max(b[i],c[i])-a[i];
		}
		else if(val==b[i]){
			vis[i]=2;
			fh[i]=max(a[i],c[i])-b[i];
		}
		else{
			vis[i]=3;
			fh[i]=max(b[i],a[i])-c[i];
		}
		sum[vis[i]]++;
		ans+=val;
	}
	int x=1;
	if(sum[2]>sum[x]) x=2;
	if(sum[3]>sum[x]) x=3;
	if(sum[x]>n/2){
		for(int i=1;i<=n;i++)
			if(vis[i]==x)
				t[++tot]=fh[i];
		sort(t+1,t+1+tot,cmp);
		for(int i=1;i<=sum[x]-n/2;i++)
			ans+=t[i];
	}
	cout<<ans<<'\n';
	Clean();
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
		work();
	return 0;
}
/*
4
4 2 1
3 2 4
5 3 4
3 5 1

*/

