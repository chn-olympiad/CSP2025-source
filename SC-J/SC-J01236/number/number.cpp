#include<bits/stdc++.h>
#define _all(i,a,b) for(int i = a; i <= b; i++)
#define __all(i,a,b) for(int i = a; i < b; i++)
#define r_all(i,a,b) for(int i = a; i >= b;i--)
#define vt vector<int>
#define vl vector<LL>
using namespace std;
using LL = long long;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	string s;
	cin>>s;
	int n = s.size();
	vt cnt(15,0);
	__all(i,0,n) cnt[(s[i] >= '0' and s[i] <='9') ? s[i] - '0' : 10] ++;
	r_all(i,9,0) while(cnt[i] > 0) printf("%d",i),cnt[i] --;
	return 0; //freopen!
}
//freopen!