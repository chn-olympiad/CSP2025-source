#include <bits/stdc++.h>
using namespace std;
int n,m,c[501];
int ans = 1;
char s;
int find(int x){
	for (int e = s.size()-1;e >= 0;e--){
		int d = 0,k = 0;
		if (s[e] == '0'){
			d++;
		}
		else{
			for (int d = 0;d < n;d++){
				if (c[d] > = d){
					k++;
				}
			}
			ans *= k;
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 0;i < n;i++){
		cin >> c[i];
	}
	find(n);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}