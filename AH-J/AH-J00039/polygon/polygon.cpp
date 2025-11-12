#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[100005];
const int Mod=998244353;
ll ans=0;
int n;
bool cmp(int x,int y){
	return x>y;
	return true;
}
void DFS(int num,int sum,int i,int maxn){//num木棍数，sum长度和，i当前下标，maxn当前最长木棍
	//cout<<num<<" "<<sum<<" "<<i<<" "<<maxn<<endl;
	if(num>=3 && sum>maxn*2){
		if(n-i+1<=20)ans+=pow(2,n-i+1);//幂值太大会爆
		else{
			ll mi=pow(2,20),tenp=1; 
			for(int i=1;i<=(n-i+1)/20;i++){
				tenp*=mi;
				tenp%=Mod;
			}
			tenp*=pow(2,(n-i+1)%20),tenp%=Mod;
			ans+=tenp,ans%=Mod;
		}
		ans%=Mod;
		return ;
	}
	if(i==n+1)return;
	DFS(num,sum,i+1,maxn);
	DFS(num+1,sum+a[i],i+1,max(maxn,a[i]));
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	DFS(0,0,1,0);
	printf("%lld",ans);
	
	return 0;
}
