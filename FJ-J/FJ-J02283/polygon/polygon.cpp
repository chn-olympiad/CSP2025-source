#include<bits/stdc++.h>
using namespace std;

int MOD=998244353;
int n,a[5005],pls,maxa;
bool flag[5005];
long long ans1;

long long bfs1(int k, int l, int num, int maxx, int ri){
	if(k==l+1){
		return num>maxx*2 ? 1 : 0;
	}
	long long ans=0;
	for(int i=ri;i<n;i++){
		if(!flag[i]){
			flag[i]=true;
			ans+=bfs1(k+1, l, num+a[i], a[i]>maxx ? a[i] : maxx, i);
//			cout<<ans<<endl;
			flag[i]=false;
		}
	}
	return ans;
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=20){
		for(int i=3;i<=20;i++){
			memset(flag, i, false);
			pls=0,maxa=0;
			ans1+=bfs1(1, i, 0, 0, 0);
		}
	}
	cout<<ans1;
	return 0;
}
