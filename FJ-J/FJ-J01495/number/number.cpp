#include <bits/stdc++.h>
using namespace std;
#define int long long
char ch[1000005];
int n[15];

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	
	cin >> ch;
	int l = strlen(ch);
	for(int i=0;i<l;i++){
		if('0'<=ch[i]&&ch[i]<='9'){
			n[ch[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=n[i];j>=1;j--){
			cout << i;
		}
	}
	
	return 0;
}
