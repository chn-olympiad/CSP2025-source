#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char c[1000005];
int mp[131];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",c);
	int len=strlen(c);
	//for(int i=0;i<len;i=i+1)printf("%c ",c[i]);
	//printf("\n");
	//test
	for(int i=0;i<len;i=i+1)mp[int(c[i])]=mp[int(c[i])]+1;
	for(int i=57;i>=48;i=i-1)
		while(mp[i]--)printf("%c",char(i));
	//output-num
	return 0;
//end-T1
//check-09:01-maybe-100
//check=11:50-100
} 
