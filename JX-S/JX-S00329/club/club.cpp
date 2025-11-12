#include <bits/stdc++.h>
#define int long long

using namespace std;
int t;
int n,num[5] = {0,0,0,0,0},ans = 0;
struct students{
	int a,b,c;
}aa[100010];
bool cmp(students a1,students a2){
	return max(max(a1.a,a1.b),a1.c) < max(max(a2.a,a2.b),a2.c);
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t --){
		num[1] = 0,num[2] = 0,num[3] = 0;
		memset(aa,0,sizeof aa);
		int dp[100010];
		memset(dp,0,sizeof dp);
		
		cin >> n;
		for(int i = 1;i <= n;i ++) cin >> aa[i].a >> aa[i].b >> aa[i].c;
		sort(aa + 1,aa + n + 1,cmp);
		int lsta = 0,lstb = 0,lstc = 0,ch[5] = {0,0,0,0,0};
		for(int i = 1;i <= n;i ++){
			//a>b,a>c
			if(aa[i].a >= aa[i].c && aa[i].a >= aa[i].b){
				if(num[1] < n / 2) num[1] ++,dp[i] = aa[i].a + dp[i - 1],lsta = i;
				else{
					if(num[2] < n / 2) ch[1] = aa[lsta].b - aa[lsta].a + aa[i].a;
					if(num[3] < n / 2) ch[2] = aa[lsta].c - aa[lsta].a + aa[i].a;
					if(num[2] < n / 2) ch[3] = aa[i].b;
					if(num[3] < n / 2) ch[4] = aa[i].c;
					sort(ch + 1,ch + 4 + 1,greater<int>());
					dp[i] = ch[1] + dp[i - 1];
					if(ch[1] == aa[lsta].b - aa[lsta].a + aa[i].a) num[2] ++,lstb = lsta,lsta = i;
					else if(ch[1] == aa[lsta].c - aa[lsta].a + aa[i].a) num[3] ++,lstc = lsta,lsta = i;
					else if(ch[1] == aa[i].b) num[2] ++,lstb = i;
					else if(ch[1] == aa[i].c) num[3] ++,lstc = i;
				} 
			}
			else if(aa[i].b >= aa[i].c && aa[i].b >= aa[i].a){
				if(num[2] < n / 2) num[2] ++,dp[i] = aa[i].b + dp[i - 1],lstb = i;
				else{
					if(num[1] < n / 2)ch[1] = aa[lstb].a - aa[lstb].b + aa[i].b;
					if(num[3] < n / 2)ch[2] = aa[lstb].c - aa[lstb].b + aa[i].b;
					if(num[1] < n / 2) ch[3] = aa[i].a;
					if(num[3] < n / 2) ch[4] = aa[i].c;
					sort(ch + 1,ch + 4 + 1,greater<int>());
					dp[i] = ch[1] + dp[i - 1];
					if(ch[1] == aa[lstb].a - aa[lstb].b + aa[i].b) num[1] ++,lsta = lstb,lstb = i;
					else if(ch[1] == aa[lstb].c - aa[lstb].b + aa[i].b) num[3] ++,lstc = lstb,lstb = i;
					else if(ch[1] == aa[i].a) num[1] ++,lsta = i;
					else if(ch[1] == aa[i].c) num[3] ++,lstc = i;
				} 
			}
			else{
				if(num[3] < n / 2) num[3] ++,dp[i] = aa[i].c + dp[i - 1],lstc = i;
				else{
					if(num[2] < n / 2)ch[1] = aa[lstc].b - aa[lstc].c + aa[i].c;
					if(num[1] < n / 2)ch[2] = aa[lstc].a - aa[lstc].c + aa[i].c;
					if(num[2] < n / 2) ch[3] = aa[i].b;
					if(num[1] < n / 2) ch[4] = aa[i].a;
					sort(ch + 1,ch + 4 + 1,greater<int>());
					dp[i] = ch[1] + dp[i - 1];
					if(ch[1] == aa[lstc].b - aa[lstc].c + aa[i].c) num[2] ++,lstb = lstc,lstc = i;
					else if(ch[1] == aa[lstc].a - aa[lstc].c + aa[i].c) num[1] ++,lsta = lstc,lstc = i;
					else if(ch[1] == aa[i].b) num[2] ++,lstb = i;
					else if(ch[1] == aa[i].a) num[1] ++,lsta = i;
				} 
			}
			//cout << dp[i] << " ";
		}
		cout << dp[n] << '\n';
	}
	
	return 0;
}
/*
 * start time:
 * end time: 
 * 
 * rp++
*/
