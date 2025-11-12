#include <bits/stdc++.h>
using namespace std;
long long n;
int a[50000];
bool f=1;
long long ksm(long long a,long long b,long long p){
	long long sum=1;
	while(b){
		if((b&1)==1){
			sum*=a;
			sum%=p;
		}
		a*=a;
		a%=p;
		b>>=1;
	}
	return sum%p;
}
bool cmp(long long a,long long b){
	return a>b;
}
long long dfs(int pos,int sum,int z,int s){
	if(pos>n){
		if(s<3)return 0;
		if(sum>z*2)return 1;
		else return 0;
	}
	long long ans=0;
	if(z==-1){
		ans+=dfs(pos+1,sum+a[pos],a[pos],s+1);
	}else ans+=dfs(pos+1,sum+a[pos],z,s+1);
	ans+=dfs(pos+1,sum,z,s);
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]>1)f=0;
	}
	sort(a+1,a+n+1,cmp);
	if(f){
		cout << ksm(2,n,998244353)-n-((n*(n-1))/2)-1;
	}else{
		cout << dfs(1,0,-1,0);
	}
	return 0;
}
