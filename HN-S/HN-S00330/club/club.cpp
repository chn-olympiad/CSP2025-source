#include<bits/stdc++.h>
#define N 100086
#define int long long
using namespace std;
int t,n,a[N],b[N],c[N],ans;
bool cmp(int x,int y);
void dfs(int cnt1,int cnt2,int cnt3,int sum,int now);
void print_nums(int x[]);
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		ans=0;
		int f1=0,f2=0,f3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]) f1=1;
			if(b[i]) f2=1;
			if(c[i]) f3=1;
		}
		if(!f2 && !f3 && f1){
			sort(a+1,a+1+n,cmp);
//			print_nums(a);
			for(int i=1;i<=n/2;i++) ans+=a[i];
		}else if(!f1 && !f3 && f2){
			sort(b+1,b+1+n,cmp);
//			print_nums(b);
			for(int i=1;i<=n/2;i++) ans+=b[i];
		}else if(!f1 && !f2 && f3){
			sort(c+1,c+1+n,cmp);
//			print_nums(c);
			for(int i=1;i<=n/2;i++) ans+=c[i];
		}else if(!f1 && !f2 && !f3){
			cout<<0<<endl;
		}else{
			dfs(0,0,0,0,1);
		}
		cout<<ans<<endl;
	}
	return 0;
}
bool cmp(int x,int y){
	return x>y;
}
void dfs(int cnt1,int cnt2,int cnt3,int sum,int now){
	if(cnt1>n/2) return;
	if(cnt2>n/2) return;
	if(cnt3>n/2) return;
	if(sum>ans) ans=sum;
	if(now>n) return;
	dfs(cnt1+1,cnt2,cnt3,sum+a[now],now+1);
	dfs(cnt1,cnt2+1,cnt3,sum+b[now],now+1);
	dfs(cnt1,cnt2,cnt3+1,sum+c[now],now+1);
}
void print_nums(int x[]){
	cout<<"the nums:";
	for(int i=1;i<=n;i++) cout<<x[i]<<" ";
	cout<<endl;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
