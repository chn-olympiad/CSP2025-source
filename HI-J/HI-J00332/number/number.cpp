#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
char s[N];
int cnt,a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	int len=strlen(s); 
	for(int i=0;i<len;i++){
		int k=s[i]-'0';
		if(k>=0 && k<=9){
			a[++cnt]=k;
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--){
		printf("%d",a[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
