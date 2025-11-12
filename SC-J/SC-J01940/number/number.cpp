#include<bits/stdc++.h>
using namespace std;

char s[1001000];
int a[1001000],cnt;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s + 1);
	int len = strlen(s + 1);
	for(int i = 1;i <= len;i++){
		if(s[i] <= '9' && s[i] >= '0'){
			a[++cnt] = s[i] - '0';
		}
	}
	sort(a + 1,a + cnt + 1);
	for(int i = cnt;i >= 1;i--){
		printf("%d",a[i]);
	}
	return 0;
}