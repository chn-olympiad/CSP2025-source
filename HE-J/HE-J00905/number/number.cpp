#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[10^6+10];
	int a[10^6+10];
	cin>>s;
	int len=strlen(s);
	for(int i=0;i<=len;i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			a[i]=s[i];
		}
	}
	sort(a+1,a+len+1);
	for(int i=1;i<=len;i++){
		cout<<a[i];
	}
	return 0;
}
