#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int T,n,dis,a[maxn][4],k[maxn],num[4];
long long ans;
void dfs(int x,long long sum){
	if(x>n){
		ans=max(ans,sum);
		return;
	}
	if(num[k[x]]+1>dis){
		if(a[x][k[x]]<=a[x-1][k[x]]){
			int tnt=a[x][k[x]],tot=0;
			a[x][k[x]]=-1;
			for(int i=1;i<=3;i++){
				if(a[x][i]>a[x][tot]){
					tot=i;	
				}
			}
			sum+=a[x][tot];
			num[tot]++;
			dfs(x+1,sum);
			a[x][k[x]]=tnt;
		}else{
			sum-=a[x-1][k[x]],num[k[x]]--;
			int tnt=a[x-1][k[x]],tot=0;
			a[x-1][k[x]]=-1;
			for(int i=1;i<=3;i++){
				if(a[x-1][i]>a[x-1][tot]){
					tot=i;	
				}
			}
			sum+=a[x-1][tot];
			num[tot]++;
			dfs(x+1,sum);
			a[x-1][k[x]]=tnt;
		}
	}else{
		sum+=a[x][k[x]];
		num[k[x]]++;
		dfs(x+1,sum);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		dis=n/2;
		for(int i=1,cnt=0;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			for(int j=1;j<=3;j++){
				if(a[i][j]>a[i][cnt]){
					cnt=j;
				
				}
			}
			k[i]=cnt;
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
} 