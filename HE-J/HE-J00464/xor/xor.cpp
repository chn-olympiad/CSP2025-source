#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int x = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		x = x * 10 + ch -'0';
		ch = getchar();
	}
	return x * f;
}

inline void out(int x)
{
	if(x < 0) putchar('-'),x = -x;
	if(x > 9) out(x / 10);
	putchar(x % 10 + '0');
}

bool cmp(int x ,int y)
{
	return x > y;
}

const int N = 2e8 + 5;
int n,k;
int a[N];
int b[N];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n = read();
	k = read();
	for(int i = 1;i <= n;++ i){
		a[i] = read();
		b[i] = (b[i - 1] ^ a[i]);
	}
	long long ans = 0;
	int  l = 0,r = 0;
	for(int i = 1;i <= n;++ i){
		for(int j = i;j <= n;++ j){
			if(i == 1){
				if(b[j] == k){
					ans ++;
					l = i;
					r = j; 
					break;
				}
			}
			else{
				if((l >= i && l <= j) || (r >= i && r <= j) || (i >= l && i <= r)|| (j >= l && j <= r)){
					if(r >= i && r <= j) break;
					else continue;
				}
				else{
					if((b[j] ^ b[i - 1]) == k){
						ans ++;
						l = i;
						r = j;
					}
				}
			}
		}
	}
	out(ans);
	return 0;
}
