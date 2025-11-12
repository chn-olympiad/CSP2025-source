#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],p=0;
char c[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",c);
	for(int i=0;i<sizeof(c);++i){
		if(c[i]>='0'&&c[i]<='9'){
			++p;
			a[p]=c[i]-'0';
		}
	}
	sort(a+1,a+p+1);
	for(int i=p;i>=1;--i)printf("%d",a[i]);
	fclose(stdin); fclose(stdout);
	return 0;
}