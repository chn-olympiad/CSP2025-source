#include<bits/stdc++.h>
using namespace std;

int n, m;

struct Node{
	int f;
	int i;
}a[110];

bool cmp(Node a, Node b){
	return a.f > b.f;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n*m; i++){
		scanf("%d", &a[i].f);
		a[i].i = i;
	}
	
	sort(a+1, a+1+n*m, cmp);
	
	int t=0;
	for(int i=1; i<=n*m; i++){
		if(a[i].i == 1){
			t = i;
			break;
		}
	}
	
	int c, r, sum=0;
	for(int i=1; i<=m; i++){
		if(i % 2 == 1){
			for(int j=1; j<=n; ++j){
				sum++;
				if(sum == t){
					c = i; r = j;
					break;
				}
			}
		}else{
			for(int j=n; j>=1; --j){
				sum++;
				if(sum == t){
					c = i; r = j;
					break;
				}
			}
		}
		if(sum == t)
			break;
	}
	printf("%d %d\n", c, r);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
