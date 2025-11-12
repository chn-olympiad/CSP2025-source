#include<bits/stdc++.h>
using namespace std;
long long x[100005],y[100005],z[100005],cnt[4];
long long ans=0;
struct node{
	long long ma,iswh;
	long long mi,towh;
}a[100005];
bool cmp(node a,node b){
	return a.mi<b.mi;
}
void work(int u,int m){
	for(int i=1;i<=2*m;i++){
		if(a[i].iswh==u){
			ans-=a[i].mi;
			cnt[u]--;
			cnt[a[i].towh]++;
		}
		if(cnt[1]<=m&&cnt[2]<=m&&cnt[3]<=m){
			cout<<ans<<'\n';
			return;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i]>>y[i]>>z[i];
			if(x[i]>=y[i]&&x[i]>=z[i]){
				a[i].ma=x[i];
				a[i].iswh=1;
				cnt[1]++;
				ans+=x[i];
				if(x[i]-y[i]<=x[i]-z[i]){
					a[i].mi=x[i]-y[i];
					a[i].towh=2;
				}else{
					a[i].mi=x[i]-z[i];
					a[i].towh=3;
				}
			} else if(y[i]>=x[i]&&y[i]>=z[i]){
				a[i].ma=y[i];
				a[i].iswh=2;
				cnt[2]++;
				ans+=y[i];
				if(y[i]-x[i]<=y[i]-z[i]){
					a[i].mi=y[i]-x[i];
					a[i].towh=1;
				}else{
					a[i].mi=y[i]-z[i];
					a[i].towh=3;
				}				
			}else if(z[i]>=x[i]&&z[i]>=y[i]){
				a[i].ma=z[i];
				a[i].iswh=3;
				cnt[3]++;
				ans+=z[i];
				if(z[i]-y[i]<=z[i]-x[i]){
					a[i].mi=z[i]-y[i];
					a[i].towh=2;
				}else{
					a[i].mi=z[i]-x[i];
					a[i].towh=1;
				}				
			} 
		}
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
			cout<<ans<<'\n';
		}else{
			sort(a+1,a+1+n,cmp);
			int p=0;
			if(cnt[1]>n/2){
				p=1;
			}else if(cnt[2]>n/2){
				p=2;
			}else if(cnt[3]>n/2){
				p=3;
			}
			work(p,n/2);
		}
	
	}
	return 0;
}
