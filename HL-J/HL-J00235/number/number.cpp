#include<bits/stdc++.h>
using namespace std;
int number[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	n=getchar();
	n=n-'0';
	number[int(n)]++;
	n=n+'0';
	while(n!='\n'){
		n=getchar();
		n=n-'0';
		if(n>=0&&n<=9)
			number[int(n)]++;
		n=n+'0';
	}
	for(int i=1;i<=number[9];i++)
		printf("9");
	for(int i=1;i<=number[8];i++)
		printf("8");
	for(int i=1;i<=number[7];i++)
		printf("7");
	for(int i=1;i<=number[6];i++)
		printf("6");
	for(int i=1;i<=number[5];i++)
		printf("5");
	for(int i=1;i<=number[4];i++)
		printf("4");
	for(int i=1;i<=number[3];i++)
		printf("3");
	for(int i=1;i<=number[2];i++)
		printf("2");
	for(int i=1;i<=number[1];i++)
		printf("1");
	for(int i=1;i<=number[0];i++)
		printf("0");
	return 0;
}
