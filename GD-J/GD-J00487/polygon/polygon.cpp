//O(INF)
#include<bits/stdc++.h>
using namespace std;
const long long p=998244353;
long long a[5005],f[5005];
long long dfs(long long c,long long d,long long um,long long ay,long long step){
	if(step==0){
		if(um>ay){
			return 1;
		}
		return 0;
	}
	long long sum=0;
	for(int i=c;i<=d;i++){
		sum+=dfs(i+1,d,um+a[i],ay,step-1);
	}
	return sum;
}
long long s(long long x,long long y){
	long long sum=0;
	for(int i=1;i<=y-x-1;i++){
		sum+=dfs(x+1,y-1,a[x],a[y],i);
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		for(int k=1;k<i;k++){
			f[i]+=f[k];
			f[i]%=p;
		}
		for(int j=1;j+2<=i;j++){
			f[i]+=s(j,i);
			f[i]%=p;
		}
	}
	cout<<f[n];
	return 0;
} 
