#include<bits/stdc++.h>
using namespace std;
long long T,n,a1,a2,a3,cnt[5],c[200000],cnt1,ans=0,ca[200000][5];
struct node{
	int num,v;
}a[200000][5];
void dfs(long long x){
	if(cnt[1]>n/2||cnt[2]>n/2||cnt[3]>n/2)
		return;
	if(x==n+1){
		cnt1=0;
		for(int i=1;i<=n;i++){
			cnt1+=ca[i][c[i]];
		}
		ans=max(ans,cnt1);
		return;
	}
	for(int i=1;i<=3;i++){
		cnt[i]++;
		c[x]=i;
		dfs(x+1);
		cnt[i]--;
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(long long i=1;i<=T;i++){
		cin>>n;
		if(n<=16){
			for(long long i=1;i<=n;i++)
				cin>>ca[i][1]>>ca[i][2]>>ca[i][3];
			dfs(1);
			cout<<ans<<endl;
			ans=0;
		}
		else{
			for(long long i=1;i<=n;i++){
				cin>>a1>>a2>>a3;
				if(a1>=a2&&a2>=a3){
					a[i][1].num=1,a[i][1].v=a1,a[i][2].num=2,a[i][2].v=a2,a[i][3].num=3,a[i][3].v=a3;
					continue;
				}
				if(a1>=a3&&a3>=a2){
					a[i][1].num=1,a[i][1].v=a1,a[i][2].num=3,a[i][2].v=a3,a[i][3].num=2,a[i][3].v=a2;		
					continue;
				}
				if(a2>=a1&&a1>=a3){
					a[i][1].num=2,a[i][1].v=a2,a[i][2].num=1,a[i][2].v=a1,a[i][3].num=3,a[i][3].v=a3;					
					continue;
				}
				if(a2>=a3&&a3>=a1){
					a[i][1].num=2,a[i][1].v=a2,a[i][2].num=3,a[i][2].v=a3,a[i][3].num=1,a[i][3].v=a1;					
					continue;
				}
				if(a3>=a1&&a1>=a2){
					a[i][1].num=3,a[i][1].v=a3,a[i][2].num=1,a[i][2].v=a1,a[i][3].num=2,a[i][3].v=a2;					
					continue;
				}
				if(a3>=a2&&a2>=a1){
					a[i][1].num=3,a[i][1].v=a3,a[i][2].num=2,a[i][2].v=a2,a[i][3].num=1,a[i][3].v=a1;					
					continue;
				}
			}
			cout<<0<<endl;
		}
	}	
	return 0;
}
