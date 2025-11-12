#include<bits/stdc++.h>
using namespace std;
int n,m,s[505],c[505]; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		char ch;
		scanf("%c",ch);
		c[int(ch)-48]++;
		if(c[int(ch)-48]>int(ch)-48){
			printf(0);
			break;
		}
	}
	return 0;
}

