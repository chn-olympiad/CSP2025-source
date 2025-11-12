#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char c[1000006];
int len;
int cnt[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",c+1);
	len=strlen(c+1);
	for(int i=1;i<=len;i++){
		if(c[i]>='0'&&c[i]<='9'){
			int sum=int(c[i]-'0');
			cnt[sum]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]>0){
			printf("%d",i);
			cnt[i]--;
		}
	}
	return 0;
}//I like yuanshen!!!
