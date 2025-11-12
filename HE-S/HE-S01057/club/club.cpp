#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,ans,dp[N];
struct node{
	int id,w_1,w_2,w_3;
}a[N];
//int W1[N],W2[N],W3[N];
bool cmp1(node x,node y){
	return x.w_1>y.w_1;
}
void solveA(){
	sort(a+1,a+1+n,cmp1);
	
	for(int i=1;i<=n/2;i++){
		ans+=a[i].w_1;
	}
	cout<<ans<<"\n";
	return ;
}
void solveB(){
	
}

void dfs(int id,int num1,int num2,int num3,int sum){
	if(id==n+1){
		ans=max(ans,sum);
		return;
	}
	
	if(num1){
//		cout<<sum;
//		sum+=a[id].w_1;
		dfs(id+1,num1-1,num2,num3,sum+a[id].w_1);
	}
	if(num2){
//		sum+=a[id].w_2;
		dfs(id+1,num1,num2-1,num3,sum+a[id].w_2);
	}
	if(num3){
//		sum+=a[id].w_3;
		dfs(id+1,num1,num2,num3-1,sum+a[id].w_3);
	}
	return;
}
void solve10(){
	dfs(1,n/2,n/2,n/2,0);
	cout<<ans<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	signed T;
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		bool flag2=true,flag3=true;
		for(int i=1;i<=n;i++){			
			cin>>a[i].w_1>>a[i].w_2>>a[i].w_3;
			if(a[i].w_2){
				flag2=false;
			}
			if(a[i].w_3){
				flag3=false;
			}
			a[i].id=i;					
		}
		
		if(flag2&&flag3){
			solveA();
			continue;
		}
//		if(flag3){
//			solveB();
//		}
		
		if(n==2){
			ans=max(a[1].w_1+a[2].w_2,a[1].w_1+a[2].w_3);
			ans=max(ans,a[1].w_2+a[2].w_1);
			ans=max(ans,a[1].w_2+a[2].w_3);
			ans=max(ans,a[1].w_3+a[2].w_1);
			ans=max(ans,a[1].w_3+a[2].w_2);
			cout<<ans<<"\n";
			continue;
		}
		if(n<=100){
			solve10();
		}
//		for(int i=1;i<=n;i++){
//			dp[i]=dp[i-1];
//		}
	}
	
	
	
	
	
	return 0;
}
