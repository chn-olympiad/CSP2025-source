#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
string s;
int vis[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
//	cout << s;
	for (char c:s){
		if (c >= '0' && c <= '9') vis[c-'0'] ++;
	}
	for(int i=9;i>=0;i--){
		rep(j,1,vis[i]) printf("%d",i);
	}
	return 0;
}

