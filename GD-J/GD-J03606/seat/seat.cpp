#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m;
const int N=1e2+2;
int a[N];
int R_ans;
int p;
int cnt;
int u,v;
int dp[22][22];
bool cmp(int a,int b){return a>b;}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R_ans=a[1];
	for(int i=1;i<=m;i++){//列
		for(int j=1;j<=n;j++){//行
			if(i%2==0)dp[n-j+1][i]=++cnt;
			else dp[j][i]=++cnt;
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(R_ans==a[i]){
			p=i;
		}//记录小R的成绩在第几位 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(p==dp[i][j]){
				u=j;
				v=i;
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
/*
2 2 
99 100 97 98 

1 2 
*/
/*
2 2 
98 99 100 97 

2 2 
*/
/*
3 3 
94 95 96 97 98 99 100 93 92 

3 1 
*/
