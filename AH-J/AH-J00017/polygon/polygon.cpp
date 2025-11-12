#include <bits/stdc++.h>
using namespace std;
const int N=5005;
int n,change[N],vis[N],ans;
struct node{
	int num,id;
}a[N];
bool cmp(node x,node y){
	return x.num<y.num;
}
bool check(int n){
	sort(change+1,change+n+1);
	int sum=0,maxn=change[n];
	for (int i=1; i<=n; i++) sum+=change[i];
	if (sum>2*maxn) return true;
	return false;
}
void dfs(int stick_tot,int num_tot,int now_tot,int tot_id){
	if (now_tot==stick_tot){
		if(check(now_tot)) ans++;
		return;
	}
	for (int i=tot_id; i<=n; i++){
		if (!vis[a[i].id]){
			vis[a[i].id]=true;
			change[++num_tot]=a[i].num;
			now_tot++;
			dfs(stick_tot,num_tot,now_tot,i+1);
			change[num_tot]=0;
			vis[a[i].id]=false;
			num_tot--;
			now_tot--;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>a[i].num;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	for (int i=3; i<=n; i++) dfs(i,0,0,1);
	cout<<ans<<endl;
	return 0;
}
