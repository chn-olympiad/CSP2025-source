#include<bits/stdc++.h>
using namespace std;

long long ans=0;
int n, l[5050], ll[5050];
int ii;

void pl(int a, int b){
	for(int i=b;i<=n-a;i++){
		ll[a]=b;
		if(a==1){
			int mx=ll[1], nn=0;
			for(int j=1;j<=ii;j++){
				mx=max(ll[j], mx);
				nn+=ll[j];
			}
			if(nn>mx*2)ans++;
		}
		else pl(a-1, i+1);
	}
	
}
int main(){
	
	freopen(polygon.in, "r", stdin);
	freopen(polygon.out, "w", stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> l[i];
	}
	sort(l+1, l+n+1);
	for(ii=3;ii<=n;ii++){
		pl(ii, 1);
	}
	cout << ans;
	
	return 0;
}
