#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define ll long long
#define N 1000005
#define PII pair<ll, ll>
#define INF (ll)1e18

using namespace std;
inline ll rd(){
	ll res=0, f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') res=(res<<3)+(res<<1)+(ch^48), ch=getchar();
	return res*f;
} 
char s[N], v[N];
int l, cnt;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf(" %s", s);
	l=strlen(s);
	for(int i=0; i<l; i++) if(s[i]>='0'&&s[i]<='9') v[++cnt]=s[i]; 
	sort(v+1, v+cnt+1, greater<char>());
	for(int i=1; i<=cnt; i++) putchar(v[i]);
	
	return 0;
}
/*

*/
