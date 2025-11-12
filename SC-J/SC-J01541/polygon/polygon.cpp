#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long m4a1[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> m4a1[i];
	}
	long long cnt=0;
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			long long mx=-1,sm=0;
			for(int k=1;k<=i;k++){
				mx=max(m4a1[j+k-1],mx);
				sm+=m4a1[j+k-1];
			}
			if(sm>mx*2){
				cnt++;
			}
		}
	}
	cout << cnt%mod+n-1;
	return 0;
}