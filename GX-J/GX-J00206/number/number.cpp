#include<iostream>
#include<algorithm>
using namespace std;
char a[1000010];
char b[1000010];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",a);
    int o=0;
    for(int i=0;a[i];i++){
		if('0'<=a[i] and a[i]<='9'){
			b[o]=a[i];
			o++;
		}
    }
    sort(b,b+o);
    for(;o>=0;o--){
		printf("%c",b[o]);
	}
}
