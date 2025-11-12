#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000001],c[1000001];
	cin>>s;
	int j = 0;
	sort(s,s+strlen(s));
	for (int i = strlen(s)-1;i>= 0;i--){
		if(s[i]>=97){
			s[i] = ' ';
		} 
		if (47 < (int)s[i] < 58){
			cout<<s[i];
		}
	}
	return 0;
}
