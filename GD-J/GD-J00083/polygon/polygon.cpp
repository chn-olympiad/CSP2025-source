#include<bits/stdc++.h>
using namespace std;

const int N=5010;
const int P=998244353;
int n,ans;
int a[N];
bool vis[N];

void dfs(int x,int k,int cnt,int sum,int mx){
	if(x>n)return;
	if(cnt>k)return;
	
	if(sum>2*mx){
		ans++;
	}
	
	vis[x]=1;
	//选这条边 
	dfs(x+1,k,cnt+1,sum+a[x],max(mx,a[x]));
	vis[x]=0;
	//不选这条边 
	dfs(x+1,k,cnt,sum,mx);
}

int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	if(n<=3){
		cout<<((a[1]+a[2]+a[3])>(2*max(a[1],max(a[2],a[3]))))?1:0;
		return 0;
	}else if(n<=20){
		for(int i=3;i<=n;i++){
			dfs(1,i,0,0,0);
		}
		cout<<ans;
	}
	
	return 0;
}
