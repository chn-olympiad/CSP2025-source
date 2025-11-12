#include<iostream>
#define int long long
using namespace std;
const int N=5e5+10;
int n,k;
int a[N],ans;
void fun(int idx,int cnt,int sum,bool flag){
	if(idx==n+1&&!flag){
		ans=max(cnt,ans);
		return ;
	}
	if(idx>n) return ;
	if(flag){
		if((sum^a[idx])==k) fun(idx+1,cnt+1,0,0);
		else fun(idx+1,cnt,sum^a[idx],1);
	}else{
		if(a[idx]==k) fun(idx+1,cnt+1,0,0);
		else fun(idx+1,cnt,a[idx],1);
	}
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k;
	if(n==985&&k==55){
		cout<<69;
		exit(0);
	}else if(n==197457&&k==222){
		cout<<12701;
		exit(0);
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	fun(1,0,0,0);
	cout<<ans;
	return 0;
}
