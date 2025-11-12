#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10;
int n,a[N],ans;
int team[N],sum,maxn;
void check(int step,int stair){
	if(step>n) return;
	for(int i=stair;i<=n;i++){
		int t=maxn;
		maxn=max(maxn,a[i]);
		team[step]=a[i];
		sum+=team[step];
		if(sum>2*maxn and step>=3){
			ans++;
//			for(int j=1;j<=step;j++) cout<<team[j]<<" ";
//			cout<<"\n";	
		}
		check(step+1,i+1);
		sum-=team[step];
		maxn=t;
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	check(1,1);
	cout<<ans%998244353;
	return 0;
}
/*

5
1 2 3 4 5
9

5
2 2 3 8 10
6

*/