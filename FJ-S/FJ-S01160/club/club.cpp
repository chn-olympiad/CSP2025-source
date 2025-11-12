#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
long long t,n,ans = 0;
long long a[50];
struct node{
	long long a;
	long long b;
	long long c;
}stu[maxn];
bool cmp(node a,node b){
	return a.a > b.a;
}
void dfs(long long x){
	if(x == n + 1){
		long long cnt1 = 0,cnt2 = 0,cnt3 = 0;
		for(int i = 1;i <= n;i++){
			if(a[i] == 1)cnt1++;
			if(a[i] == 2)cnt2++;
			if(a[i] == 3)cnt3++;
		}
		if(cnt1 <= n / 2 && cnt2 <= n / 2 && cnt3 <= n / 2){
			long long cnt = 0;
			for(int i = 1;i <= n;i++){
				if(a[i] == 1)cnt += stu[i].a;
				if(a[i] == 2)cnt += stu[i].b;
				if(a[i] == 3)cnt += stu[i].c;
			}
			ans = max(ans,cnt);
		}
		return;
	}
	for(int i = 1;i <= 3;i++){
		a[x] = i;
		dfs(x + 1);
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		ans = 0;
		memset(a,0,sizeof(a));
		memset(stu,0,sizeof(stu));
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> stu[i].a >> stu[i].b >> stu[i].c;
		}
		bool flag = true;
		for(int i = 1;i <= n;i++){
			if(stu[i].b != 0 || stu[i].c != 0){
				flag = false;
			}
		}
		if(flag){
			sort(stu + 1,stu + n + 1,cmp);
			for(int i = 1;i <= n / 2;i++){
				ans += stu[i].a;
			}
			cout << ans << endl;
		}else{
			bool flag = true;
			for(int i = 1;i <= n;i++){
				if(stu[i].c != 0){
					flag = false;
				}
			}
			if(flag){
				long long c1 = 0,c2 = 0;
				
			}else{
				dfs(1);
				cout << ans << endl;
			}
		}
	}
	return 0;
}
