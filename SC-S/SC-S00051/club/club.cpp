#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,pair<ll,ll>>
#define mk make_pair
using namespace std;
const int N=1e5+5;
struct node{
	ll a1,a2,a3;
}stu[N];
ll arr[N],cnt;
ll T,n,sum,ans;

bool cmp(ll x,ll y) {return x>y;}
void solve(){
	sum=cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>stu[i].a1>>stu[i].a2>>stu[i].a3;
		sum+=stu[i].a1;
	}
//	cout<<sum<<' ';
	for(int i=1;i<=n;i++) arr[++cnt]=max(stu[i].a2-stu[i].a1,stu[i].a3-stu[i].a1);
	sort(arr+1,arr+cnt+1,cmp);
	for(int i=1;i<=n/2;i++){
//		cout<<arr[i]<<' ';
		sum+=arr[i];
	} 
	ans=sum;
	
	
	sum=cnt=0;
	for(int i=1;i<=n;i++) sum+=stu[i].a2;
	for(int i=1;i<=n;i++) arr[++cnt]=max(stu[i].a1-stu[i].a2,stu[i].a3-stu[i].a2);
	sort(arr+1,arr+cnt+1,cmp);
	for(int i=1;i<=n/2;i++){
//		cout<<arr[i]<<' ';
		sum+=arr[i];
	} 
	ans=max(ans,sum);
	
	
	sum=cnt=0;
	for(int i=1;i<=n;i++) sum+=stu[i].a3;
	for(int i=1;i<=n;i++) arr[++cnt]=max(stu[i].a1-stu[i].a3,stu[i].a2-stu[i].a3);
	sort(arr+1,arr+cnt+1,cmp);
	for(int i=1;i<=n/2;i++){
//		cout<<arr[i]<<' ';
		sum+=arr[i];
	} 
	ans=max(ans,sum);
	
	
	cout<<ans<<'\n';
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>T;
	while(T--) solve();
	return 0;
}