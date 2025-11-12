#include<bits/stdc++.h> 
using namespace std;
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);		
	int n,m,p[110],op,j;
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= m * n;i++){
		scanf("%d",&p[i]);
		if(i == 1) op = p[i];
	}
	sort(p,p + m * n + 1,cmp);
	for(j = 1 ; j <= m * n;j++){
		if(p[j] == op) break;
	}
	if(j / n % 2 == 0 && j % n != 0) printf("%d %d",j / n + 1,j % n);
	else if (j / n % 2 == 0 && j % n == 0) printf("%d %d",j / n,1);
	else if (j / n % 2 == 1 && j % n != 0) printf("%d %d",j / n + 1,n - (j % n) + 1);
	else if (j / n % 2 == 1 && j % n == 0) printf("%d %d",j / n,n);
	return 0;
}
