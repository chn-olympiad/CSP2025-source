#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000010]={'\0'},n[1000010]={'\0'};
	int j=0;
	scanf("%s",s);
	for(int i=0;s[i]!='\0';i++){
	    if(s[i]>='0' && s[i]<='9'){
			n[j++]=s[i];
		}
	}
	sort(n,n+j,greater<char>());
	printf("%s",n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
