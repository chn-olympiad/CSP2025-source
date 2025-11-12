#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
template <typename T> inline void read(T &x){
	x = 0;
	LL f = 1;
	char c = getchar();
	for(; !isdigit(c); c=getchar()) if(c == '-') f = -1;
	for(; isdigit(c); c=getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	x *= f;
}
template <typename T> inline void print(T x){
	if(x < 0) x = -x,putchar('-');
	if(x > 9) print(x / 10);
	putchar(x % 10 + 48);
}
inline void sprint(const string s){
	for(auto x : s) putchar(x);
	return;
}
const int N = 1e5 + 11;
string s;
priority_queue<int,vector<int>,less<int>> q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n = s.size();
	for(int i=0;i<n;i++){
		if(s[i] >= '0' && s[i] <= '9') q.emplace(s[i] - '0');
	}
	while(q.size()){
		print(q.top());
		q.pop();
	} 
	return 0;
}
