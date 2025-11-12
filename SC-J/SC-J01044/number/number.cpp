#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char a[N];
int b[N],g=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=strlen(a);
	for(int i=0;i<len;++i)
		if(a[i]>='0' && a[i]<='9'){
			b[g]=a[i]-'0';
			g++;
		}
	sort(b+1,b+g);
	for(int i=g-1;i>=1;--i)
		printf("%d",b[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//I love shishi high school 