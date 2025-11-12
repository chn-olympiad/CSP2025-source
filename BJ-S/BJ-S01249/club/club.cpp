#include<bits/stdc++.h>
using namespace std;
struct node{
	int c[4];
	int d[3];
	int cd12;
}a[100010];
int cnt[4]={0,0,0,0},ans=0,n;
bool cmp(node n1,node n2){
	return n1.cd12<n2.cd12;
}
void dfs(int j){
	for(int i=j;i<=n;i++){
		if(a[i].cd12!=0){
			if(a[i].c[1]==a[i].d[1]){
				if(cnt[1]<n/2){
					cnt[1]++;
					ans+=a[i].d[1];
				}
				else{
					if(a[i].c[2]==a[i].d[2]){
						cnt[2]++;
						ans+=a[i].d[2];
					}
					else{
						cnt[3]++;
						ans+=a[i].d[2];
					}
				}
			}
			else if(a[i].c[2]==a[i].d[1]){
				if(cnt[2]<n/2){
					cnt[2]++;
					ans+=a[i].d[1];
				}
				else{
					if(a[i].c[3]==a[i].d[2]){
						cnt[3]++;
						ans+=a[i].d[2];
					}
					else{
						cnt[1]++;
						ans+=a[i].d[2];
					}
				}
			}
			else{
				if(cnt[3]<n/2){
					cnt[3]++;
					ans+=a[i].d[1];
				}
				else{
					if(a[i].c[2]==a[i].d[2]){
						cnt[2]++;
						ans+=a[i].d[2];
					}
					else{
						cnt[1]++;
						ans+=a[i].d[2];
					}
				}
			}
		}
		else{
			if(a[i].c[1]==a[i].d[1]){
				cnt[1]++;
				ans+=a[i].d[1];
				dfs(i+1);
				int ans1=ans;
				cnt[1]--;
				ans-=a[i].d[1];
				int ans2;
				if(a[i].c[2]==a[i].d[2]){
					cnt[2]++;
					ans+=a[i].d[2];
					dfs(i+1);
					ans2=ans;
					cnt[2]--;
					ans-=a[i].d[2];
				}
				else{
					cnt[3]++;
					ans+=a[i].d[2];
					dfs(i+1);
					ans2=ans;
					cnt[3]--;
					ans-=a[i].d[2];
				}
				ans=max(ans1,ans2);
				return;
			}
			else if(a[i].c[2]==a[i].d[1]){
				cnt[2]++;
				ans+=a[i].d[1];
				dfs(i+1);
				int ans1=ans;
				cnt[2]--;
				ans-=a[i].d[1];
				int ans2;
				if(a[i].c[3]==a[i].d[2]){
					cnt[3]++;
					ans+=a[i].d[2];
					dfs(i+1);
					ans2=ans;
					cnt[3]--;
					ans-=a[i].d[2];
				}
				else{
					cnt[1]++;
					ans+=a[i].d[2];
					dfs(i+1);
					ans2=ans;
					cnt[1]--;
					ans-=a[i].d[2];
				}
				ans=max(ans1,ans2);
				return;
			}
			else{
				cnt[3]++;
				ans+=a[i].d[1];
				dfs(i+1);
				int ans1=ans;
				cnt[3]--;
				ans-=a[i].d[1];
				int ans2;
				if(a[i].c[2]==a[i].d[2]){
					cnt[2]++;
					ans+=a[i].d[2];
					dfs(i+1);
					ans2=ans;
					cnt[2]--;
					ans-=a[i].d[2];
				}
				else{
					cnt[1]++;
					ans+=a[i].d[2];
					dfs(i+1);
					ans2=ans;
					cnt[1]--;
					ans-=a[i].d[2];
				}
				ans=max(ans1,ans2);
				return;
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].c[1]>>a[i].c[2]>>a[i].c[3];
			a[i].d[1]=max(max(a[i].c[1],a[i].c[2]),a[i].c[3]);
			int d3=min(min(a[i].c[1],a[i].c[2]),a[i].c[3]);
			for(int j=1;j<=3;j++){
				if(a[i].c[j]!=a[i].d[1]&&a[i].c[j]!=d3)a[i].d[2]=a[i].c[j];
			}
			a[i].cd12=a[i].d[1]-a[i].d[2];
		}
		sort(a+1,a+n+1,cmp);
		cnt[1]=0;cnt[2]=0;cnt[3]=0;ans=0;
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
