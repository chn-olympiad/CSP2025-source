#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
char s[N];
int a[N],k;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	scanf("%s",s);
	for(int i = 0;i<strlen(s);i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++k] = s[i]-'0';
		}
	}
	sort(a+1,a+k+1);
	for(int i = k;i>=1;i--){
		printf("%d",a[i]);
	}
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}
