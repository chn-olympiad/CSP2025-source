#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 105;
int h[MAXN] = {};

bool cmp(int a, int b){
	return a>b; 
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, t = -1;
	scanf("%d %d", &n, &m);
	for(int i = 1; i<=n*m; i++){
		scanf("%d", &h[i]);
		if(i == 1) t = h[i];
	}
	
	sort(h+1, h+n*m+1, cmp);
	
	int ti = -1;
	for(int i = 1; i<=n*m; i++){
		if(h[i] == t){
			ti = i;
			break;
		}
	}
	int l = (ti+n-1)/n, r;
	int f = ti%n==0?n:ti%n;
	if(l%2 == 0)
		r = n-f+1;
	else{
		r = f;
	}
	printf("%d %d", l, r);
	return 0;
}

