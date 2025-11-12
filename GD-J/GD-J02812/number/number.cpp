#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000001];
	int k=0, c[1000001];
	scanf("%s",s);
	for(int i=0,len=strlen(s);i<len;i++){
		if(s[i]<='z'&&s[i]>='a'){
			continue;
		}
		else{
			c[k]=(int)(s[i])-48;
			k++;
		}
	}
	sort(c,c+k,cmp);
	for(int i=0;i<k;i++){
		printf("%d",c[i]);
	}
	return 0;
}
