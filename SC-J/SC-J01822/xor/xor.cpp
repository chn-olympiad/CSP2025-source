#include<bits/stdc++.h>
using namespace std;
int a[500005][25];
struct node{
	int i;
	int j;
}v[600506];
int n,k,k1[25];
bool cmp(int x,int y){
	for(int i = 1;i <= 21;i++){
		if((a[x][i]- a[y-1][i])%2 != k1[i]){
			//cout << i << " "<<a[x][i]<<","<<a[y-1][i];
			return false;
		}
	}
	return true;
}
int dp[600605];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n >>k;
	int tmp;
	int len = 0;
	while(k){
		k1[++len] = k%2;
		k/=2;
	}
	for(int i = 1;i <= n;i++){
		cin >> tmp;
		int l = 1;
		while(tmp){
			a[i][l] = tmp%2;
			tmp/=2;
			l++;
		}
		
	}
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= 21;j++){
			a[i][j] = a[i][j] + a[i-1][j];
			//cout <<a[i][j];
		}
		//cout <<endl;
	}
	//for(int i = 1;i <= 21;i++)cout << k1[i];
	//cout << '\n';
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= i;j++){
			//cout << j << "," << i << " " ;
			if(cmp(i,j)){v[++cnt].i = i;v[cnt].j = j;}
			//cout << endl;
		}
	}
	for(int i = 1;i <= cnt;i++){
		dp[i] = 1;
		for(int j = 1;j < i;j++){
			if(v[i].j > v[j].i)dp[i] = max(dp[i],dp[j] + 1);
		}
	}
	int ans = -0x3f3f3f3f;
	for(int i = 1;i <= cnt;i++)ans = max(ans,dp[i]);
	cout <<ans;
	return 0;
}