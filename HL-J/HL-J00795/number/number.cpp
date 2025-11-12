#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
char s[N];
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s", s);
	int len=strlen(s),n=0;
	for(int i=0;i<len;i++){
		if('0'<=s[i]&&s[i]<='9'){
			n++;
			a[n]=s[i]-'0';
		}
	}
	sort(a+1,a+n+1);
	if(a[n]==0){
		printf("0");
		return 0;
	}
	for(int i=n;i>=1;i--){
		printf("%d", a[i]);
	}
	return 0;
}