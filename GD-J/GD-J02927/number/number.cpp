#include<bits/stdc++.h>
using namespace std;
int a[15];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int len = s.size();
	for (int i = 0;i < len;i++){
		if (isdigit(s[i])){
			int k = s[i] - '0';
			a[k]++;
		}
	}
	for (int i = 9;i >= 0;i--){
		for (int j = 1;j <= a[i];j++){
			cout << i; 
		}
	}
	
	return 0;
}
/*Notes: 
*/
