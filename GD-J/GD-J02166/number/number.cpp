#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1010;
char s[N];
int n;
int a[N],l=0;

bool cmp(const int &x,const int &y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[++l]=s[i]-'0';
	sort(a+1,a+l+1,cmp);
	for(int i=1;i<=l;i++)
	 	printf("%d",a[i]);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
