#include <cstdio>
#define rep(i, j, k) for(int i = (j); i <= ((int)(k)); i++)
#define rrep(i, j, k) for(int i = (j); i >= ((int)(k)); i--)
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;
int a[maxn][3][3];

inline int read(void){
	int ans = 0;
	char c = getchar();
	while(c < '0' || c > '9'){
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		ans = ans * 10 + c - '0';
		c = getchar();
	}
	return ans;
}

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n = read(), q = read();
	int qq[3][3];
	char c = getchar();
	rep(i, 1, n){
		while(c != 'a' && c != 'b'){
			c = getchar();
		}
		while(c == 'a'){
			a[i][1][1]++;
			c = getchar();
		}
		c = getchar();
		while(c == 'a'){
			a[i][1][2]++;
			c = getchar();
		}
		while(c != 'a' && c != 'b'){
			c = getchar();
		}
		while(c == 'a'){
			a[i][2][1]++;
			c = getchar();
		}
		c = getchar();
		while(c == 'a'){
			a[i][2][2]++;
			c = getchar();
		}
	}
	int ans;
	while(q--){
		qq[1][1] = qq[1][2] = qq[2][1] = qq[2][2] = 0;
		while(c != 'a' && c != 'b'){
			c = getchar();
		}
		while(c == 'a'){
			qq[1][1]++;
			c = getchar();
		}
		c = getchar();
		while(c == 'a'){
			qq[1][2]++;
			c = getchar();
		}
		while(c != 'a' && c != 'b'){
			c = getchar();
		}
		while(c == 'a'){
			qq[2][1]++;
			c = getchar();
		}
		c = getchar();
		while(c == 'a'){
			qq[2][2]++;
			c = getchar();
		}
		if(qq[1][1] + qq[1][2] != qq[2][1] + qq[2][2]){
			printf("0\n");
			continue;
		}
		ans = 0;
		rep(i, 1, n){
			if(a[i][1][1] <= qq[1][1] && a[i][1][2] <= qq[1][2]){
				if(qq[1][1] - a[i][1][1] + a[i][2][1] == qq[2][1]){
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
