#include <iostream>
#include <string>
#include <algorithm> 
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, k;
	cin>>n>>k;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	int cnt = 0;
	for(int i=1;i<=n;i++){
		long long now = 0;
		for(int j=i;j<=n;j++){
			now ^= a[j];\
			//cout<<"i:"<<i<<" j:"<<j<<'\n';
			if(now == k){
				i = j;
				cnt++;
				now = 0;
				break;
			}
		}
	}
	cout<<cnt; 
	
	/*
	vector<vector<long long> >f(n+1,vector<long long>(n+1));
	//	f[x][r]:a当前选择组数为x，最后一个区间的右边界为r的异或值 
	int nwx =  (a[i] == k);
	f[nwn][nwn] = a[i];
	for(int i=2;i<=n;i++){
		for(int j = 1; j <= i;j++){//j:右边界 
			if(f[nwx][j] != k){
				f[nwn][j] ^= a[i];
			}else{
				f[nwn + 1][i] = f[nwn][j] ^ a[i];
				nwn++;//???
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(f[nxt][])
	}
	*/
	return 0;
}
