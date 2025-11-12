#include <bits/stdc++.h>
using namespace std;
int n, a[100002][5], b[100002], T, ans, cnt1, cnt2, cnt3, cnt;
pair<int, int> p[100002];
bool t1, t2;
bool cmp1(int x, int y){
	return x>y;
}
bool cmp2(pair<int, int> x, pair<int, int> y){
	return x.first-x.second>y.first-y.second;
}
void dfs(int x){
	if(x==n+1){
		ans=max(ans, cnt);
		return;
	}
	if(cnt1<n/2){
		cnt1++, cnt+=a[x][1];
		dfs(x+1);
		cnt1--, cnt-=a[x][1];
	}
	
	if(cnt2<n/2){
		cnt2++, cnt+=a[x][2];
		dfs(x+1);
		cnt2--, cnt-=a[x][2];
	}
	
	if(cnt3<n/2){
		cnt3++, cnt+=a[x][3];
		dfs(x+1);
		cnt3--, cnt-=a[x][3];
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>T;
	while(T--){
		t1=t2=1, ans=0;
		cin>>n;
		for(int i = 1; i <= n; i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]){
				t1=0;
			}
			if(a[i][3]){
				t1=t2=0;
			}
		}
		if(t1){
			for(int i = 1; i <= n; i++){
				b[i]=a[i][1];
			}
			sort(b+1, b+n+1, cmp1);
			for(int i = 1; i <= n/2; i++){
				ans+=b[i];
			}	
		}
		else if(t2){
			for(int i = 1; i <= n; i++){
				p[i]={a[i][1], a[i][2]};
			}
			sort(p+1, p+n+1, cmp2);
			for(int i = 1; i <= n/2; i++){
				ans+=p[i].first;
			}
			for(int i = n/2+1; i <= n; i++){
				ans+=p[i].second;
			}
		}
		else{
			dfs(1);
		}
		cout<<ans<<endl;
	}
}