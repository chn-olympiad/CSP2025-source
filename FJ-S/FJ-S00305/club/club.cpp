#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n,T;
int a[MAXN][5];
int cnt[5];
int req;
int maxn[MAXN];

bool cmp1(int a,int b){
	return a > b;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		int ans = 0;
		bool flag1 = 0;
		bool flag2 = 0;
		memset(maxn,-114514,sizeof(maxn));
		cin>>n;
		req = n / 2;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++){
				cin>>a[i][j];
				maxn[i] = max(maxn[i],a[i][j]);
				if(a[i][2] != 0 && a[i][3] != 0){
					flag1 = 1;
				}
				if(a[i][3] != 0){
					flag2 = 1;
				}
			}			
		}
		if(flag1 == 0){
			sort(maxn + 1,maxn + n + 1,cmp1);
			for(int i = 1;i <= req;i++){
				ans += maxn[i];
			}
			cout<<ans<<endl;
		}
	//	else{
		/*	if(flag2 == 0){
				//sort(a + 1,a + n + 1,cmp2);
				//sort(a + 1,a + n + 1,cmp3);
				for(int i = 1;i <= n;i++){
					ans += a[i][1];
					ans += a[i][2];
				}
			}*/
			else{
				for(int i = 1;i <= n;i++){
					ans += maxn[i];
				}
				cout<<ans<<endl;
			}
		}
	//}
	return 0;
}
