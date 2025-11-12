#include<bits/stdc++.h>
#define int long long
using namespace std;

char s;
int l[15];

signed main(void){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(scanf("%c",&s)!=EOF)
		if(s>='0'&&s<='9')l[s-'0']++;
	
	for(int i=9;i>=0;i--)
		for(int j=0;j<l[i];j++)
			printf("%d",i);
	return 0;
}
/*
5

5
----
290es1q0

92100
*/

