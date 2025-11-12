#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int dp[N][N][3],n,ans;
int s[N][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	int a,b,c;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a,&b,&c);
		ans+=max(a,max(b,c));
	}
	cout<<ans;
	return 0;
} 
/*
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
