#include <bits/stdc++.h>
using namespace std;
long long metrial[15][15];
long long scores[105];
bool cmp(long long x,long long y){
	if(x < y)return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	long long k = m*n;
	for(long long i = 0;i < k;i++){
		cin >> scores[i];
	}
	long long rs = scores[0];
	sort(scores,scores+k,cmp);
	long long cnt = 0;
	long long stj = 0;
	while(stj < m){
		if((stj+1) % 2 == 0){
			long long i = n;
			while(i--){
				metrial[i][stj] = scores[cnt];
				cnt++;
			}
			stj++;
		}else if((stj+1) % 2 != 0){
			for(long long i = 0;i < n;i++){
				metrial[i][stj] = scores[cnt];
				cnt++;
			}
			stj++;
		}
	}	
	for(long long i = 0;i < n;i++){
		for(long long j = 0;j < m;j++){
			if(metrial[i][j] == rs){
				cout << j+1 << " " << i+1 << endl;
				break;
			}
		}
	}
	
	
	
	return 0;
}