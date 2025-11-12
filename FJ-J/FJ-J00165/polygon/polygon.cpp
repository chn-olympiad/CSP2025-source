#include <bits/stdc++.h>
using namespace std;
int n[10001];
int a;
int ans = 0;
int b = 1;
int y = 1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> a;
	for(int i=0;i<a;i++) cin >> n[i];
	sort(n,n+a);
	if(a<3) cout << 0;
	for(int i=0;i<a;i++){
		for(int j=b;j<a;j++){
			if(n[i]+n[j]+n[j+1]>2*n[j+1]) ans++;
			if(b==a-1){
				b = y+1;
				y = b;
			}
		}
	}
	
	
	cout << ans-9;
	return 0;
}
