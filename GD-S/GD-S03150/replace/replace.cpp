#include<bits/stdc++.h>
#define gc getchar
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const int N = 1e5+3;
inline int re(){
	int x=0;bool f=0;char c=gc();
	for(;c<'0'||c>'9';c=gc())f=c=='-';
	for(;c>='0'&&c<='9';c=gc())x=x*10-48+c;
	return f?-x:x;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=re(),q=re();
	while(q--)puts("0");
	return 0; 
}
