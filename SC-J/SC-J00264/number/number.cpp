#include <bits/stdc++.h>
using namespace std;
char s;
int num[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(s=getchar(),s!='\n')
		if(s>='0'&&s<='9')
			num[s-'0']++;
	for(int i=9;i>=0;i--){
		for(int j=0;j<num[i];j++){
			printf("%d",i);
		}
	}
	return 0;
}