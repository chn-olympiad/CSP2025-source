#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
bool flag,flag1;
int T,n,a[N][5],aa[N],ans,cnt[5];
struct node{
	int cf,mx;
}s[N];
bool cmp(node a,node b){
	return a.cf<b.cf;
}
void dfs(int k,int sum){
	if(k==n+1){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]<n/2){
			cnt[i]++;
			dfs(k+1,sum+a[k][i]);
			cnt[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		flag=flag1=1;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]&&j!=1)flag=0;
				if(a[i][3])flag1=0;
			}
		}
		if(n<200){
			cnt[1]=cnt[2]=cnt[3]=0;
			dfs(1,0);
			cout<<ans<<"\n";
		}
		else{
			if(flag){
				for(int i=1;i<=n;i++){
					aa[i]=a[i][1];
				}
				sort(aa+1,aa+1+n);
				for(int i=n;i>=n/2;i--){
					ans+=aa[i];
				}
			}
			if(flag1){
				int sum=0;
				for(int i=1;i<=n;i++){
					if(a[i][1]>a[i][2]){
						s[i].mx=1;
						sum++;
					}
					else{
						s[i].mx=2;
					}
					s[i].cf=max(a[i][1],a[i][2])-min(a[i][1],a[i][2]);
					ans+=max(a[i][1],a[i][2]);
				}
				sort(s+1,s+1+n,cmp);
				while(sum>n/2){
					for(int i=1;i<=n;i++){
						if(s[i].mx==1){
							sum--;
							ans-=s[i].cf;
						}
					}
				}
				while(sum<n/2){
					for(int i=1;i<=n;i++){
						if(s[i].mx==2){
							sum++;
							ans-=s[i].cf;
						}
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
} 
