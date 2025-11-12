#include<bits/stdc++.h>
using namespace std;
char aa[1000010];
int bb[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",aa);
	int a=strlen(aa);
	for(int i=0;i<a;i++) if(aa[i]>='0'&&aa[i]<='9') bb[aa[i]-'0']++;
	for(int i=9;i>=0;i--) for(int j=1;j<=bb[i];j++) printf("%d",i);
	return 0;
}
