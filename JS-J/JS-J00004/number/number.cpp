#include <bits/stdc++.h>
using namespace std;
char c[1000010];
int a[20];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",c);
    for(int i=0;i<1000005;i++){
	    if(c[i]>='0'&&c[i]<='9'){
		    a[c[i]-'0']++;
		}
	}
    for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
		    printf("%d",i);
		}
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
