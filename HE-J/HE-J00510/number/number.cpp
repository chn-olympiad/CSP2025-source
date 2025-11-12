#include <bits/stdc++.h>
using namespace std;
char s[1000010],a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<strlen(s);i++){
		if(s[i]>=48&&s[i]<=57){
			a[i]=s[i];
		}
	}
	sort(a,a+strlen(s));
	for(int i=strlen(s)-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
