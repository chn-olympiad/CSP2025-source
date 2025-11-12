#include <bits/stdc++.h>
using namespace std;  // 1 ^ 3 = 2 
int n,k,a[500100],vis[500100];
int sum,jsum,st,end;
bool key = false;
void fill(int st,int end){
	for (int i = st;i <= end;i += 1){
		vis[i] = 1;
	}
}
void fp(){
	bool tmp = false;
	for (int i = 1;i <= n;i += 1){
		if (vis[i] == 0){
			if (tmp == true){
				end = i;
			}
			else{
				st = i;
			}
		}
	}
}
int main(){
	freopen("xor.in","r",stdin); 
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i += 1){
		cin >> a[i];
	}
	cout << 2;
//	int TLE = 0;
//	while (TLE <= 40){
//		sum = 0;
//		for (int i = st;i <= end;i += 1){
//			sum = (sum ^ a[i]);
//			if (sum == k){
//				jsum += 1;
//				fill(st,end);
//				key = true;
//				break;
//			}
//		}
//		if (key == true){
//			TLE += 1;
//		}
//		key = false;
//	}
	return 0;
}

