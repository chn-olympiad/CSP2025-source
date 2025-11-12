#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char pos='9';pos>='0';pos--){
		for(int i=0;s[i]>0;i++){
			if(s[i]==pos)cout<<s[i];
		}
	}
	return 0;
}
