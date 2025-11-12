#include <bits/stdc++.h>
using namespace std;
const int Mod =  998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int le[n];
	for(int i = 0;i<n;i++){
		cin >> le[i];
	}
	long long cnt = 0;
	for(int i = 0;i<n;i++){
		for(int j = i+2;j<n;j++){
			int maxn = -1,mnt = 0;
			for(int v = i;v<=j;v++){
				maxn = max(maxn,le[v]);
				mnt += le[v];
			}
			if(maxn*2<mnt) cnt++;
		}
	}
	cout<<cnt%Mod;
	return 0;
}