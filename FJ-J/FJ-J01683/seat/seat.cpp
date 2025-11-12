#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int a[105], scor, x=1, y=1, chos;
int add[2]={1, -1};

bool cmp(int a, int b){
	return a>b;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n*m;i++){
		scanf("%d", &a[i]);
	}
	scor=a[1];
	
	sort(a+1, a+n*m+1, cmp);
	
	for(int i=1;i<=n*m;i++){
		if(a[i] == scor){
			printf("%d %d", y, x);
		}
		
		if(i%n == 0){
			y++;
			chos+=1;
			chos%=2;
			continue;
		}
		
		x+=add[chos];
	}
	return 0;
}
