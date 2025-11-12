#include<bits/stdc++.h>
using namespace std;
#define freop(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout);
#define ll long long
#define lb long double
#define re register
#define endl '\n'
#define pii pair<int,int>
#define fir first
#define sec second
string s;
int a[10]; 

int main(){
	cin.tie(0)->ios::sync_with_stdio(0);
	cout.tie(0);
	freop("number");
//以上为初始化
//--------------------------------------
	cin >> s;
	for(char c:s) if(isdigit(c)) ++a[c-'0'];
	for(int i = 9;~i;--i)
		while(a[i]--) cout << i;
	return 0;
}
/*

*/ 
