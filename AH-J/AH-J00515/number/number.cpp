#include <bits/stdc++.h>
using namespace std;
int a[10]={0};

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    char x;
    while (scanf("%c",&x)!=EOF){
        if (x>='0' && x<='9'){
            a[x-'0']++;
        }
    }
	for(int i=9;i>=0;i--)
		while(a[i]--)
			printf("%d",i);
	printf("\n");
    return 0;
}


