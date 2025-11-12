#include<bits/stdc++.h>
using namespace std;
char c[1000005];
int a[1000005],ai,ci;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",c);
	ci=strlen(c);
	for(int i=0;i<ci;i++){
		if(c[i]>='0' && c[i]<='9'){
			a[ai++]=c[i]-'0';
		}
	}
	sort(a,a+ai,greater<int>());
	for(int i=0;i<ai;i++){
		printf("%d",a[i]);
	}
	return 0;
}
