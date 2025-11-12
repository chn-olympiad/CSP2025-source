#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int a[N],b[N],c[N];
int n;
int cnt[4]; 
bool cmp(int x,int y){
	return x>y;
}
int a1,b1,c1;
int maxn=0;
void dfs(int step,int ans){
	if(step==n+1){
		maxn=max(maxn,ans);
		return ;
	}
	if(a1<n/2){
		a1++;
		dfs(step+1,ans+a[step]);
		a1--;
	}
	if(b1<n/2){
		b1++;
		dfs(step+1,ans+b[step]);
		b1--;
	}
	if(c1<n/2){
		c1++;
		dfs(step+1,ans+c[step]);
		c1--;
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		maxn=0;
		a1=b1=c1=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n<30){
			dfs(1,0);
			cout<<maxn<<'\n';
			continue;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(a[i]>=b[i]&&a[i]>=c[i]){
				if(cnt[1]<n/2){
					ans+=a[i];
					cnt[1]++;
				}
				else{
					if(b[i]>c[i]){
						ans+=b[i];
						cnt[2]++;
					}
					else{
						ans+=c[i];
						cnt[3]++;
					}
				}
			}
			else if(b[i]>=a[i]&&b[i]>=c[i]){
				if(cnt[2]<n/2){
					ans+=b[i];
					cnt[2]++;
				}
				else{
					if(a[i]>c[i]){
						ans+=a[i];
						cnt[1]++;
					}
					else{
						ans+=c[i];
						cnt[3]++;
					}
				}
			}
			else if(c[i]>=a[i]&&c[i]>=b[i]){
				if(cnt[3]<n/2){
					ans+=c[i];
					cnt[3]++;
				}
				else{
					if(a[i]>b[i]){
						ans+=a[i];
						cnt[1]++;
					}
					else{
						ans+=b[i];
						cnt[2]++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
