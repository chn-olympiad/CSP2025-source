#include<bits/stdc++.h>
using namespace std;
const int M = 1e5+10;
int t,n,m;
long long a[M][4],f[M][4],dp[4];//dp_q[M][4];
long long ans[10],u,v;

void s_sort(int x){
	for(int i=3;i>1;i--){
		for(int j=1;j<i;j++){
			if(a[x][j] < a[x][j+1] ){
				swap(a[x][j],a[x][j+1]);
				swap(f[x][j],f[x][j+1]);
			}
		}
	}
	return;
}

void l_sort(int x){
	for(int i=n;i>1;i--){
		for(int j=1;j<i;j++){
			if(a[j][x] < a[j+1][x]){
				for(int k=1;k<=3;k++){
					swap(a[j][k],a[j+1][k]);
					swap(f[j][k],f[j+1][k]);
				}
			}
		}
	}
	return;
}
/*
int s_max(long long x){
	long long y=1,p = -1;
	if(x == n+1) return 0; 
	while(y<=3){
		int z = f[x][y];
		if(dp[z]<m){
			dp[z]++;
			p = max(p,s_max(x+1)+a[x][y]);
		}
	}
	return p;
}*/

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		m = n/2;
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		//memset(dp_q,0,sizeof(dp_q));
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin>>a[j][k];
				f[j][k] = k;
			}
			s_sort(j);
			//cout<<"test:"<<a[j][1]<<" "<<a[j][2]<<" "<<a[j][3]<<endl;
		}
		l_sort(1);
		//for(int j=1;j<=n;j++)cout<<"2 test:"<<a[j][1]<<" "<<a[j][2]<<" "<<a[j][3]<<endl;
		
		//ans[i] = s_max(1);
		
		for(int j=1;j<=n;j++){
			u = 1;
			while(u<=3){
				v = f[j][u];
				//cout<<"P:"<<v<<endl;
				if(dp[v]<m){
					dp[v]++;
					ans[i]+=a[j][u];
				//	cout<<"++N:"<<a[j][u]<<endl;
					break;
				}
				else{
					u++;
				}
			
			}/*
			for(int v=n;v>=1;v--){
				for(int u=1;u<=3;u++){
					if(dp[v][u] < dp[v-1][u]+a[j][u]&&dp_q[f[j][u]]<m){
						dp[v][u]=dp[v-1][u]+a[j][u];
						dp_q[f[j][u]]++;
					}
				}
			}
		}
		ans[i] = max(max(dp[n][3],dp[n][2]),dp[n][1]);*/
		}
	}
	for(int i=0;i<t;i++)cout<<ans[i]<<endl;
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0

2
10 9 8
4 0 0
*/
