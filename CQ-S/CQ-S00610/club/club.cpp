#include<bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int t,n,arr[100005][5],brr[5][100005],num[5],ans,now,maxx,minn;

bool cmp(int a,int b){
	int mina = 0x7fffffff,minb = 0x7fffffff;
	for(int i=1;i<=3;i++){
		if(i != now){
			mina = min(mina,arr[a][now] - arr[a][i]);
			minb = min(minb,arr[b][now] - arr[b][i]);
		}
	}
	return mina > minb;
}

signed main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> t;
	while(t--){
		ans = now = 0;
		for(int i=1;i<=3;i++){
			num[i] = 0;
		}
		cin >> n;
		for(int i=1;i<=n;i++){
			maxx = 0;
			for(int j=1;j<=3;j++){
				cin >> arr[i][j];
				maxx = max(maxx,arr[i][j]);
			}
			ans += maxx;
			for(int j=1;j<=3;j++){
				if(arr[i][j] == maxx){
					num[j]++;
					brr[j][num[j]] = i;
					break;
				}
			}
		}
		for(int i=1;i<=3;i++){
			if(num[i] > n / 2){
				now = i;
				break;
			}
		}
		if(now == 0){
			cout << ans <<endl;
		}
		else{
			sort(brr[now] + 1,brr[now] + 1 + num[now],cmp);
			for(int i=num[now];i>n/2;i--){
				minn = 0x7fffffff;
				for(int j=1;j<=3;j++){
					if(j != now){
						minn = min(minn,arr[brr[now][i]][now] - arr[brr[now][i]][j]);
					}
				}
				ans -= minn;
			}
			cout << ans <<endl;
		}
	}
	
	
	return 0;
}
