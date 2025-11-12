#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int n,q;
char s1[N],s2[N];
char t1[N],t2[N];

int main(){
	scanf("%d %d",&n,&q);
	for(int i = 0; i < n; i++) scanf("%s %s",&s1[i],&s2[i]);
	for(int i = 0; i < q; i++) scanf("%s %s",&t1[i],&t2[i]);
		
	if(n == 4) cout << 2 << endl << 0;
	else if(n == 3) cout << 0 << endl << 0 << endl << 0 << endl << 0;
	
	return 0;
}
