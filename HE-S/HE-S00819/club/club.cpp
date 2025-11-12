#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int N=1e5+5;
int T,n,a[N][5],cnt,cnt1,cnt2,tot,ans,tmp[N],delta[N],num[5];
inline void dfs(int pos,int c1,int c2,int c3,int sum){
	if(pos==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(c1<n/2) dfs(pos+1,c1+1,c2,c3,sum+a[pos][1]);
	if(c2<n/2) dfs(pos+1,c1,c2+1,c3,sum+a[pos][2]);
	if(c3<n/2) dfs(pos+1,c1,c2,c3+1,sum+a[pos][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		ans=cnt1=cnt2=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j==2&&a[i][j]==0) cnt1++;
				if(j==3&&a[i][j]==0) cnt2++;
			}
		}
		if(n==2){
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i==j) continue;
					ans=max(ans,a[1][i]+a[2][j]);
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		if(n==4){
			dfs(1,0,0,0,0);
			cout<<ans<<'\n';
			continue;
		}
		if(cnt1==n&&cnt2==n){
			for(int i=1;i<=n;i++) tmp[i]=a[i][1];
			sort(tmp+1,tmp+1+n);
			for(int i=n;i>n/2;i--)ans+=tmp[i];
			cout<<ans<<'\n';
			continue;
		}
		if(cnt2==n){
			tot=cnt=0;
			for(int i=1;i<=n;i++) if(a[i][1]>a[i][2]) cnt++;
			if(cnt<n/2) for(int i=1;i<=n;i++) swap(a[i][1],a[i][2]);
			cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i][1]>a[i][2]){
					cnt++;
					ans+=a[i][1];
					delta[++tot]=a[i][1]-a[i][2];
				}else ans+=a[i][2];
			}
			if(cnt==n/2){
				cout<<ans<<'\n';
				continue;
			}
			sort(delta+1,delta+1+tot);
			for(int i=1;i<=cnt-n/2;i++) ans-=delta[i];
			cout<<ans<<'\n';
			continue;
		}
	}
	return 0;
}

/*
1
6
6 3 0
5 9 0
4 2 0
3 7 0
2 1 0
8 4 0


1
6
3 6 0
9 5 0
2 4 0
7 3 0
1 2 0
4 8 0

1
4
4 2 1
3 2 4
5 3 4
3 5 1

*/
