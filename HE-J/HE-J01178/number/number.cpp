#include <bits/stdc++.h>
using namespace std;
int sum[10];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char c;
	while(1){
		c=getchar();
		if(!(c>='0'&&c<='9'||c>='a'&&c<='z'))break;
		if(c>='0'&&c<='9')sum[c-'0']++;
	}
	for(int i=9;i>=0;i--)
		for(int j=0;j<sum[i];j++)
			printf("%d",i);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//hope 100
