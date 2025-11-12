#include<bits/stdc++.h>
using namespace std;
int a[100005][5];
int sl[100005];
int cnt[5];
struct node{
	int v , i;
} mess[100005];
bool cmp(node p , node q){
	return p.v > q.v;
}
//燃尽了 不是吧为啥大样例都过了唯一的一个小样例WA了啊 真的不可理喻啊这代码
//代码爹%%%多给我混点分行不彳亍  orz
//while(1) rp++;
//现在求神都没用了我真的好绝望 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	int t;
	cin >> t;
	while(t --){
		int n;
		cin >> n;
		for(int i = 1;i <= 3;i ++) cnt[i] = 0;
		int flag1 , flag2;
		flag1 = flag2 = 0;
		for(int i = 1;i <= n;i ++)
			for(int j = 1;j <= 3;j ++){
				cin >> a[i][j];
				if(j == 2 && a[i][j] != 0) flag1 = 1;
				if(j == 3 && a[i][j] != 0) flag2 = 1;
			}
		if(!flag1 && !flag2){
			for(int i = 1;i <= n;i ++) sl[i] = a[i][1];
			sort(sl + 1 , sl + 1 + n);
			int ans = 0;
			for(int i = n;i >= n / 2;i --) ans += sl[i];
			cout << ans << '\n';
			continue;
		}
		if(!flag2){
			for(int i = 1;i <= n;i ++) mess[i].v = a[i][2] - a[i][1] , mess[i].i = i;
			sort(mess + 1 , mess + 1 + n , cmp);
			int ans = 0;
			for(int i = 1;i <= n / 2;i ++) ans += a[mess[i].i][2];
			for(int i = n / 2 + 1;i <= n;i ++) ans += a[mess[i].i][1];
			cout << ans << '\n';
			continue;
		}
		for(int i = 1;i <= n;i ++){
			int ma = INT_MIN;
			for(int j = 1;j <= 3;j ++){
				ma = max(ma , a[i][j]);
			}	
			if(a[i][1] == ma) cnt[1] ++;
			if(a[i][2] == ma) cnt[2] ++;
			if(a[i][3] == ma) cnt[3] ++;
		}
		long long ans = 0;
		if(cnt[1] > n / 2){
			for(int i = 1;i <= n;i ++) a[i][2] = max(a[i][2] , a[i][3]) , mess[i].v = a[i][1] - a[i][2] , mess[i].i = i;
			sort(mess + 1 , mess + 1 + n , cmp);
			for(int i = 1;i <= n / 2;i ++) ans += a[mess[i].i][1];
			for(int i = n / 2 + 1;i <= n;i ++) ans += a[mess[i].i][2];
			cout << ans << '\n';
			continue;
		}	
		if(cnt[2] > n / 2){
			for(int i = 1;i <= n;i ++) a[i][1] = max(a[i][1] , a[i][3]) , mess[i].v = a[i][2] - a[i][1] , mess[i].i = i;
			sort(mess + 1 , mess + 1 + n , cmp);
			for(int i = 1;i <= n / 2;i ++) ans += a[mess[i].i][2];
			for(int i = n / 2 + 1;i <= n;i ++) ans += a[mess[i].i][1];
			cout << ans << '\n';
			continue;
		}
		if(cnt[3] > n / 2){
			for(int i = 1;i <= n;i ++) a[i][1] = max(a[i][1] , a[i][2]) , mess[i].v = a[i][3] - a[i][1] , mess[i].i = i;
			sort(mess + 1 , mess + 1 + n , cmp);
			for(int i = 1;i <= n / 2;i ++) ans += a[mess[i].i][3];
			for(int i = n / 2 + 1;i <= n;i ++) ans += a[mess[i].i][3];
			cout << ans << '\n';
			continue;
		}
		for(int i = 1;i <= n;i ++) ans += max(a[i][1] , max(a[i][2] , a[i][3]));
		cout << ans << '\n';
	}
	return 0;
} 

