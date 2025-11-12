#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int b[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int a=strlen(s),c=0;
	for(int i=0;i<a;i++){
		if((s[i]>='0')&&(s[i]<='9')){
			b[++c]=int(s[i]-'0');
		}
	}
	sort(b+1,b+1+c);
	for(int i=c;i>=1;i--){
		cout<<b[i];
	}
	return 0;
}
