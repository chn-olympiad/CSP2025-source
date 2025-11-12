#include <bits/stdc++.h>
using namespace std;
const int o=1e6+10;
char a[o];
int b[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("unmber.out","w",stdout);
	scanf("%s",a);
	int h=strlen(a);
	for(int i=0;i<h;i++){
		if(a[i]>='0' and a[i]<='9'){
			b[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int k=0;k<b[i];k++){
			printf("%d",i);
		}
	}
	return 0;
}
