#include<iostream>
#include<cmath>
using namespace std;
const int MOD=998244353;
int sum,maxx,n,a[5005],cnt;
bool check(int s,int mx){
	if(s>2*mx){
		return 1;
	}else{
		return 0;
	}
}
void dfs(int i,int s){
	if(i>n){
		if(check(sum,maxx)&&s>2){
			cnt++;
			cnt%=MOD;
			
		}
		return ;
	}
	dfs(i+1,s);
	sum+=a[i];
	int t=maxx;
	maxx=max(a[i],maxx);
	dfs(i+1,s+1);
	sum-=a[i];
	maxx=t;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<cnt;
}
