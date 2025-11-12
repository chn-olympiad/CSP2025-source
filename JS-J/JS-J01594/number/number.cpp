#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[10],p;
char b[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",b);
	for(int i=0;i<(int)strlen(b);i++){
		p=b[i]-'0';
		if(p>9||p<0) continue;
		a[p]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++) printf("%d",i);
	}
	return 0;
}

