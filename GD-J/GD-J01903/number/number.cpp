#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char s[N];
int a[N],l,cnt=0;
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf(" %s",s);
	l=strlen(s);
	cnt=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++cnt]=(s[i]-'0');
		}
	}
	sort(a+1,a+1+cnt,cmp);
	if(a[1]==0)printf("0");
	else{
		for(int i=1;i<=cnt;i++){
			printf("%d",a[i]);
		}
	}
	return 0;
} 
