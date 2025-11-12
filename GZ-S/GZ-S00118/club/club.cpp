//GZ-S00118 安顺市第一高级中学 商裕如
#include <bits/stdc++.h>

#define DLC using
#define Is namespace
#define Neko std
DLC Is Neko;
#define MAXN -11451419
#define ios ios::sync_with_stdio(false),cin.tie(0)

const int MINN=0x7fffffff;

const int N=1e5+5;
int a[N][3];
int dp[N][3];
int cnt[N]={0};
int n;

int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	
	ios;int t;cin >> t;
	while(t--){
		cin >> n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin >> a[i][j];
			}
		}
		int sum=0;
		
		for(int i=1;i<=n;i++){
			//dp[i][2]=0;
			int maxy[N];
			if(a[i][2]==0&&a[i][3]==0){
				maxy[i]=max(MAXN,a[i][1]);
			}
			else{
				for(int j=1;j<=3;j++){
					maxy[i]=max(a[i][j],maxy[i]);
					if(maxy[i]==a[i][j])cnt[j]++;
					if(cnt[j]>n/2){
						a[i][j]=0;
						continue;
						
					}
				}
				
			}
			
			sum+=maxy[i];
			//cout << maxy[i];
		}
		cout <<sum;
	}
	
	
	return 0;
}
