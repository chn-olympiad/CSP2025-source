#include<bits/stdc++.h>
#define ll long long
using namespace std;
char s[1000006];
int a[1005],n;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;++i){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a[i]=s[i]-'0';
		}
		else{
			a[i]=-1;
		}
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;++i){
		if(a[i]==-1){
			break;
		}
		printf("%d",a[i]);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
