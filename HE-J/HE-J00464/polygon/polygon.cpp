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

const int N = 1e8 + 5;
int n;
int a[N];
int ans,maxn = -1e8;
int mod = 998244353;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    n = read();
    if(n < 3){
    	out(0);
    	return 0;
	}
	else if(n == 3){
        for(int i = 1;i <= n;++ i){
    	    a[i] = read();
    	    maxn = max(maxn,a[i]);
    	    ans += a[i];
	    }	
	    if(ans > 2 * maxn){
	    	out(1);
	    	return 0;
		}
		else{
			out(0);
			return 0;
		}
	}
	else{
		cout << pow(2,n);
	}
	return 0;
}
