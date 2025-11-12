#include<bits/stdc++.h>
using namespace std;
const int M=1e6+10;
char s[M];
int a[M],t,n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++t]=s[i]-'0';
			for(int i=t;i>1;i--){
				if(a[i]<=a[i-1])
					break;
				int x=a[i];
				a[i]=a[i-1];
				a[i-1]=x;
			}
		}
	}
	for(int i=1;i<=t;i++)
		printf("%d",a[i]);
	return 0;
}
