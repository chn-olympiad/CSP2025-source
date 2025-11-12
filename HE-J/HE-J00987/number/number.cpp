#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	int a,l,cnt=0;
	char s[9100];
	for(int i=0;i<91;i++){
		cin>>s[i];
		if(s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9'){
			cout<<s[i];
		}
	}
	return 0;
}
