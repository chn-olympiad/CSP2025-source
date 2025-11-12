#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char c[N];
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",c+1);
	int s=strlen(c+1),t=0;
	for(int i=1;i<=s;i++){
		if(c[i]>='0'&&c[i]<='9') a[++t]=c[i]-'0';
	}
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++) printf("%d",a[i]);
	
	return 0;
}
