#include<bits/stdc++.h>
using namespace std;
int k,b[15];
char a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a);
	int l=strlen(a);
	for(int i=1;i<l;i++){
		if('0'<=a[i]&&a[i]<='9')b[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=b[i];j++)printf("%d",i);
	}
	return 0;
}
