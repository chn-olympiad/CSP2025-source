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

const int N = 1e4 + 5;
int n,m;
int a[N]; 

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    n = read();
    m = read();
    for(int i = 1;i <= n * m;++ i){
    	a[i] = read();
	}
	int r = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	int i = 0,j = 1;
	int ans = 0;
	while(a[ans] != r)
	{
		if(j % 2 == 1 && i < n){
			i ++;
			ans ++;
		}
		else{
			if(j % 2 == 1 && i >= n){
				j ++;
				ans ++;
			}
			else if(j % 2 == 0 && i <= n && i > 1){
				i --;
				ans ++;
			}
			else{
				j ++; 
				ans ++;
			}
		}
	}
    out(j);
    printf(" ");
    out(i);
	return 0;
}
