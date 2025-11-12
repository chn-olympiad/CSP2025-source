#include <bits/stdc++.h>
using namespace std;
int n,m,cnt;
int s[5007];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> s[i];
		m = max(m,s[i]);
	}
	if(n < 3){
		cout << 0;
		return 0;
	}
	if(n == 3){
		if(s[1]+s[2]+s[3] > 2*m)cout << 1;
		else cout << 0;
		return 0;
	}
	for(int i = 1;i <= n-2;i++){
		for(int j = i+1;j <= n-1;j++){
			for(int k = j+1;k <= n;k++){
				if(s[i]+s[j]+s[k] > 2*(max(max(s[i],s[j]),s[k]))) cnt++;	
			}
		}
	}
	cout << cnt;
	return 0;
}
