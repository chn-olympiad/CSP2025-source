#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sort(s,s+strlen(s),greater<char>());
	for(int i=0;i<strlen(s);i++){
		if(s[i]>='0' && s[i]<='9'){
			for(int j=i;j<strlen(s);j++){
				if(s[j]>='0' && s[j]<='9') cout<<s[j];
				else break;
			}break;
		}
	}return 0;
}
