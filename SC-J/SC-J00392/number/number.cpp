#include <bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int idx=0;
	char c;
	c=getchar();
	while(c!='\n'&&c!='\0'&&c!=EOF){
		if(c>='0'&&c<='9')a[c-48]++;
		c=getchar();
	}
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			for(int j=1;j<=a[i];j++)putchar(i+48);
		}
	}
	return 0;
}