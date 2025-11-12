#include<bits/stdc++.h>
using namespace std;
char s[1000000+50];
char ss[10]= {9,8,7,6,5,4,3,2,1};
int a[1000000+50];
int main () {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int slen=strlen(s);
	sort(s,s+slen);
	for(int i=slen; i>=0; i--) {
		if(s[i]<='9'&&s[i]>='0') {
			cout<<s[i];
		}
	}
	return 0;
}
