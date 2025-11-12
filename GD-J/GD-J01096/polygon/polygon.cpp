#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const long long mod=998244353;
long long n,a[5005],ans=0;
int v[5005];
void dfs(long long mx,long long sum,long long x,long long w){
//	cout<<x<<endl;
	if(sum>mx*2){
		ans=(ans+1)%mod;
		v[mx]++;
	}
	for(int i=x+w;i>=1&&i<=n;i+=w){
		if(a[i]>mx)	continue;
		sum+=a[i];
		dfs(mx,sum,i,w);
		sum-=a[i];
	}
	return;
}
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		dfs(a[i],a[i],i,1);
		dfs(a[i],a[i],i,-1);
//		cout<<a[i]<<' '<<v[a[i]]<<endl;
	}
	cout<<(ans)%mod<<endl;
	return 0;
}
//5
//1 2 3 4 5
//9

//5
//2 2 3 8 10
//6

//20 
//75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1
//1042392


