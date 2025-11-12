#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define endl '\n'
const int N = 1e5+5;
const int base = 1e9+7;
const int mod = 998244353;
ll read(){
	ll x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0'){ x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return x*f;
}
void write(ll x){
	if(x<0){putchar('-');x=-x;}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int n,q;
pii a[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n = read();
	m = read();
	for(int i = 1 ; i <= n ; i ++){
		
	}
	return 0;
}
// today im so tired and dont have enough sleep,it makes me feels no power to deal with those hard problems.
//through T2 seems to be faced and T3 is about trie tree , i forget them at all certainly
//you may have a problem:why you speak english instead of chinese?whats wrong with you.
//because it cant be change corectly in devc++ you know that

//i want to write some more and get more pts but im really so tired and can make me awake
//its a little pity to get lower than 1= in my last dance in csp-s
//IT'S REALLY THE FATE I CANT CHANGE
