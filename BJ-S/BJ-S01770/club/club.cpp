#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
int n;
int a[114514][11];
/*bool case1,case2,case3;
int dp[114][114][114];
void solve1(){
	memset(dp,0,sizeof(dp));
	int ans = 0;
	for(int i = 1;i<=n;i++){
		for(int j = n/2;j>=1;j--){
			for(int k = n/2;k>=1;k--){
				for(int l = n/2;l>=1;l--){
					if((i+j+k) > n)continue;
					dp[j][k][l] = max(max(dp[j][k][l],dp[j-1][k][l]+a[i][1]),max(dp[j][k-1][l]+a[i][2],dp[j][k][l-1]+a[i][3]));
					ans = max(ans,dp[j][k][l]);
				}
			}
		}
	}
	cout<<ans<<'\n';
	return ;
}*/
vector<int> vec;
int maxpos[114514],secpos[114514],bar[11];
void solve2(){
	memset(bar,0,sizeof(bar));
	int ans = 0;
	vec.clear();
	int cha = 0;
	int MINN;
	for(int i = 1;i<=n;i++){
		cha += min(a[i][1],min(a[i][2],a[i][3]));
		MINN = min(a[i][1],min(a[i][2],a[i][3]));
		a[i][1] -= MINN,a[i][2] -= MINN,a[i][3] -= MINN;
		if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]){
			maxpos[i] = 1;
			if(a[i][2] > a[i][3]){
				secpos[i] = 2;
			}else{
				secpos[i] = 3;
			}
		}else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]){
			maxpos[i] = 2;
			if(a[i][3] > a[i][1]){
				secpos[i] = 3;
			}else{
				secpos[i] = 1;
			}
		}else if(a[i][3] > a[i][2] && a[i][3] > a[i][1]){
			maxpos[i] = 3;
			if(a[i][2] > a[i][1]){
				secpos[i] = 2;
			}else{
				secpos[i] = 1;
			}
		}
		bar[maxpos[i]]++;
		ans += max(a[i][1],max(a[i][2],a[i][3]));
	}
	//cout<<cha<<' '<<ans<<'\n';
	int pos = 0;
	if(bar[1] > n/2){
		pos = 1;
		for(int i = 1;i<=n;i++){
			if(maxpos[i] == 1){
				vec.push_back(a[i][1]-a[i][secpos[i]]);
			}
		}
	}else if(bar[2] > n/2){
		pos = 2;
		for(int i = 1;i<=n;i++){
			if(maxpos[i] == 2){
				vec.push_back(a[i][2]-a[i][secpos[i]]);
			}
		}
	}else if(bar[3] > n/2){
		pos = 3;
		for(int i = 1;i<=n;i++){
			if(maxpos[i] == 3){
				vec.push_back(a[i][3]-a[i][secpos[i]]);
			}
		}
	}
	sort(vec.begin(),vec.end());
	int idx = 0;
	while(bar[pos] > n/2){
		ans -= vec[idx];
		idx++;
		bar[pos]--;
	}
	cout<<ans+cha<<'\n';
	return ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		//case1 = 1;
		for(int i = 1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			//if(a[i][3] != 0){
			//	case1 = 0;
			//}
		}
		solve2();
		/*
		if(n <= 30){
			solve1();
		}else if(case1){
			solve2();
		}*/
	}
	return 0;
}
/**
 4
4 2 1
3 2 4
5 3 4
3 5 1
 */
