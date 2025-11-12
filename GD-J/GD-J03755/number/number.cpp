#include <bits/stdc++.h>
using namespace std;
char s[1000010];
int ls,xb,a[1000010];
int main(){
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	cin>>s;
	ls=strlen(s);
	for(int i=0;i<ls;i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			xb++;
			a[xb]=s[i]-48;
		}
	}
	sort(a+1,a+xb+1);
	for(int i=xb;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
