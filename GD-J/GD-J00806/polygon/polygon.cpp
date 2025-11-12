#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+3,mod=998244353;
int n,mx;
ll ans,C[N][N];
int a[N],mi[N];
bool cmp(int x,int y){return x>y;}
void dfs(int k,int x,int sum,int cnt){
//	cout<<k<<" "<<x<<" "<<sum<<" "<<cnt<<endl;
	if(sum>a[k]&&cnt>1){
//		cout<<"oiiaio";
		int m=n-x+1;
		if(k>x)m--;
		ans=(ans+mi[m])%mod;
		return; 
	} 
	if(x>n)return;
	dfs(k,x+1,sum+a[x],cnt+1);
	dfs(k,x+1,sum,cnt);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
//  Æ­ÄãµÄÎûÎû 
	scanf("%d",&n);
	mi[0]=1;
	for(int i=1;i<=n;i++)mi[i]=mi[i-1]*2%mod;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
	}
	sort(a+1,a+n+1,cmp);
	if(mx>1){
		for(int i=1;i<=n;i++){
			dfs(i,i+1,0,0);
		}
		printf("%lld",ans);
	}
	else{
		C[1][1]=1;
		for(int i=2;i<=n+1;i++){
			for(int j=1;j<=i;j++){
				C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
//				cout<<C[i][j]<<" ";
			}
//			cout<<endl;
		}
		for(int i=3;i<=n;i++){
			ans=(ans+C[n+1][i+1])%mod; 
		}
		printf("%lld",ans);
	} 
	return 0;
}
//4 1 1 1 1
//6 1 1 1 1 1 1
