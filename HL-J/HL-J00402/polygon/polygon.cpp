#include <bits/stdc++.h>
using namespace std;
int s[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin>>s[i];
	}
	int ans = max(s[3],max(s[1],s[2]));
	if(2*ans<s[1]+s[2]+s[3]){
		cout << 1;
	}

	return 0;
}
