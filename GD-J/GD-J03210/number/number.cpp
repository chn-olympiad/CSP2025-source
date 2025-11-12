#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char s[N];
int t=0,a[N],n;
inline bool cmp(const int &x,const int &y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++){
		if(s[i]<='9'&&s[i]>='0')
			a[++t]=s[i]-'0';
	}
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++)
		printf("%d",a[i]);
	printf("\n");
	return 0;
}
