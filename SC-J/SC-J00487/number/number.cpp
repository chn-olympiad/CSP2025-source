#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10; 
char s[N];
int x[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	int n=strlen(s);
	int j=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			x[j++]=s[i]-'0';
		}
	}
	sort(x,x+j);
	for(int i=j-1;i>=0;i--){
		printf("%d",x[i]);
	}
	return 0;
}