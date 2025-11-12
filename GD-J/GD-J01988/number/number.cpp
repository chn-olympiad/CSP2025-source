#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
char a[MAXN];
int n,b[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a);
	n=strlen(a);
	for(int i=0;i<n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
		for(int j=1;j<=b[i];j++)printf("%d",i);
	return 0;
} 
