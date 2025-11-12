#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int MAXN=1e5+5;
const int INF=2e9;

int t,n;
int a[MAXN][4],b[MAXN],d[MAXN];
int seq[MAXN],m,num;
int sum,cnt[4];

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		sum=0;
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			for(int j=1;j<=3;j++){
				if(a[i][j]==max(max(a[i][1],a[i][2]),a[i][3])){
					sum+=a[i][j];
					cnt[j]++;
					d[i]=j;
					b[i]=INF;
					for(int k=1;k<=3;k++){
						if(k==j) continue;
						b[i]=min(b[i],a[i][j]-a[i][k]);
					}
					break;		
				}
			}
		}
		num=m=0;		
		for(int i=1;i<=3;i++){
			if(cnt[i]>n/2){
				num=cnt[i]-n/2;
				for(int j=1;j<=n;j++){
					if(d[j]==i){
						seq[++m]=b[j];
					}
				}
				sort(seq+1,seq+m+1);
				for(int j=1;j<=num;j++){
					sum-=seq[j];
				}
				break;
			}
		}
		cout<<sum<<'\n';
	}	
	return 0;
} 
//100 pts?
/*

首先不管n/2的限制，贪心的选择每个人的最大满意度的部门.

再考虑部门的限制，选择更改部门后满意度减少最少的人更改. 
 
 
RP++.


*/
