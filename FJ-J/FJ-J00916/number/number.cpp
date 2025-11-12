#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int a[1000005],b,c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	b=strlen(s);
	for(int i=0;i<b;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[c]=s[i]-'0';
			c++;
		}
	}
	sort(a,a+c);
	for(int i=c-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
