#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char s[N];
int a[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	int l=strlen(s);
	for(int i=0;i<l;++i){
		if(s[i]>='0'&&s[i]<='9'){
			a[int(s[i]-'0')]+=1;
			}
	}
	for(int i=9;i>=0;--i){
		if(a[i]!=0){
			for(int j=1;j<=a[i];++j){
				printf("%d",i);
				}
			}
		}
	return 0;
}
