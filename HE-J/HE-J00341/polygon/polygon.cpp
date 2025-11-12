#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=5100;
int n,a[N],ans;
void fun(int x,int id,int ma,int sum,bool r){
//x:选到了第x个 id:已经选了id个 
//r:上一个是否拿了，拿了就判断，没拿就不判断 
	if(id>=3&&sum>ma*2&&r)ans++,ans%=mod;	
	if(x==n+1)return;
	fun(x+1,id+1,max(ma,a[x]),sum+a[x],1);
	fun(x+1,id,ma,sum,0);
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=1)sum++;
	}
	fun(1,0,0,0,0);
	cout<<ans%mod<<'\n';
	return 0;
}
