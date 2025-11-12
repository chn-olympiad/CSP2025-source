#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e5+7;
ll a[N][4],n,t,b[N],ans,sum[4],cnt;
struct node {
	ll s,dd;
}c[4];
bool cmp(node s1,node s2){
	return s1.s>s2.s;
} 
int f(int id,int d){
	for(int i=1;i<=3;i++){
		c[i].s=a[id][i];
		c[i].dd=i;
	}
	sort(c+1,c+3+1,cmp);
	return c[d].dd;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0; 
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			sum[f(i,1)]++;
			ans+=a[i][f(i,1)];
		}
		for(int i=1;i<=3;i++){
			if(sum[i]>n/2){
				for(int j=1;j<=n;j++)if(f(j,1)==i)b[++cnt]=a[j][f(j,1)]-a[j][f(j,2)];
				sort(b+1,b+cnt+1);
				for(int j=1;j<=sum[i]-n/2;j++)ans-=b[j];
			}
		}
		for(int i=1;i<=cnt;i++)b[i]=0;
		sum[1]=sum[2]=sum[3]=0;
		cnt=0;
		cout<<ans<<"\n";
	}
	return 0;
} /*
4 
4 2 1 
3 2 4 
5 3 4 
3 5 1 
*/
