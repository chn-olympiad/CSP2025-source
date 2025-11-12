#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n;
char c[N],a[N];
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin),freopen("number.out","w",stdout);
	scanf("%s",c);
	for(int i=0;c[i];i++){
		if('0'<=c[i]&&c[i]<='9')a[n++]=c[i];
	}
	sort(a,a+n,cmp);
	printf("%s\n",a);
	fclose(stdin),fclose(stdout);
	return 0;
}