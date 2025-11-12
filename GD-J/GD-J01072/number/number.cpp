#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int a[1000005],x = 1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&s);
	for(int i = 0; i < 1000005;i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[x] = s[i] - '0';
			x ++;
		}
	}
	sort(a + 1,a + x + 1);
	for(int i = x; i >= 2; i--) printf("%d",a[i]);
	return 0;
}
