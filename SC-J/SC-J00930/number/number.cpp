#include<bits/stdc++.h>
using namespace std;
char a[10006],noww[10005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long i=0,l=0;
	scanf("%s",&a);
	while(a[l]!='\0'){
		if('0'<=a[l]&&'9'>=a[l]){
			noww[l]=a[l];
			sort(noww,noww+l,greater<long long>());
		}
		l++;
	}
	l=0;
	while(noww[l]!='\0'){
		printf("%c",noww[l]);
		l++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}