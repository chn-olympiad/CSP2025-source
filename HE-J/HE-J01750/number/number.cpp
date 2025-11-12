#include<iostream>
#include<cstring>
const int N = 1e6 + 5;
int mp[10],n;
char a[N];
bool flag;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a + 1);
	n = strlen(a + 1);
	for(int i = 1;i <= n;i ++){
		if(a[i] <= '9' && a[i] >= '0'){
			mp[a[i] - '0'] ++;
		}
	}
	for(int i = 9;i >= 0;i --){
		if(flag || i){
			for(int j = 1;j <= mp[i];j ++){
				putchar(i + '0');
			}
			if(mp[i]) flag = 1;
		}else{
			putchar('0');
		}
	}
	putchar('\n');
} 
