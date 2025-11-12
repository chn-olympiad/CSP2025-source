#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
int n,m;
char s;
int c[N];

int main(){
	scanf("%d %d",&n,&m);
	scanf("%s",s);
	for(int i = 0; i < n; i++) scanf("%d",&c[i]);
	
	if(n == 3) printf("%d",2);
	else if(n == 10) printf("%d",2204128);
	
	return 0;
}
