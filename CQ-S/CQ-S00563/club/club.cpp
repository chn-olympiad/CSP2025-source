#include <bits/stdc++.h>
using namespace std;
int T,n,num1,num2,num3,ans,d1,d2,d3;
struct node{ int A[3],x,se; }a[100005],cnt1[100005],cnt2[100005],cnt3[100005];
bool cmp(node a,node b){ return a.se-a.x>b.se-b.x; }
void solve(){
	cin >> n,num1=num2=num3=ans=0;
	for(int i=1;i<=n;i++){
		cin >> d1 >> d2 >> d3;
		a[i].A[0]=d1,a[i].A[1]=d2,a[i].A[2]=d3;
		sort(a[i].A,a[i].A+3),a[i].x=a[i].A[2],a[i].se=a[i].A[1];
		if(a[i].x==d1) cnt1[++num1]=a[i];
		else if(a[i].x==d2) cnt2[++num2]=a[i];
		else cnt3[++num3]=a[i];
		ans+=a[i].x;
	} if(num1<=n/2 && num2<=n/2 && num3<=n/2) return cout << ans << '\n',void();
	if(num1>n/2){
		sort(cnt1+1,cnt1+num1+1,cmp);
		for(int i=1;i<=num1-n/2;i++) ans+=cnt1[i].se-cnt1[i].x;
	}else if(num2>n/2){
		sort(cnt2+1,cnt2+num2+1,cmp);
		for(int i=1;i<=num2-n/2;i++) ans+=cnt2[i].se-cnt2[i].x;
	}else{
		sort(cnt3+1,cnt3+num3+1,cmp);
		for(int i=1;i<=num3-n/2;i++) ans+=cnt3[i].se-cnt3[i].x;
	} cout << ans << '\n'; 
} int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> T; while(T--) solve(); return 0;
}
