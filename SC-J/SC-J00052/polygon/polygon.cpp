#include <bits/stdc++.h>
using namespace std;
int a[10010],dp[10010],s[10010];
const int MOD=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.in","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	int sum=0;
	bool q=1,w=1,e=1,r=1;
	for(int i=3;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(s[i-1]<a[i]) break;
			if(s[i-1]-a[j]<a[i]&&q){
				sum+=j;
				sum%=MOD;
				q=0;
			} 
			if(s[i-1]-a[i-j]<a[i]&&w){
				sum+=j;
				sum%=MOD;
				w=0;
			}
		}
	}cout<<1;
	return 0;
} 
/*
5
1 2 3 4 5

5
2 2 3 8 10
*/