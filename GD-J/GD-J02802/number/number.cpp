#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char s[1000005];
int main(){	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sort(s,s+strlen(s));
	for(int i=strlen(s);i>=0;i--){
		if(s[i]>='0'&&s[i]<='9'){
			cout<<s[i];
		}
	}
	return 0;
}
