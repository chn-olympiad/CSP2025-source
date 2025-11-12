#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define mod 1000000007
#define ari(x) array<int,(x)>
#define lcm(x,y) x/__gcd(x,y)*y
#define lowbit(x) ((x) & -(x))

string s;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	for(auto c : s) if(isdigit(c)) a[c-'0']++;
	for(int i = 9;i >= 0;i--) while(a[i]--) cout<<i;
	return 0;
}
