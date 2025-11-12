#include<bits/stdc++.h>
using namespace std;

string str;
char s[1000005];
int n;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;str[i]>='0';i++){
		if(str[i]>='0'&&str[i]<='9'){
			n++;
			s[n]=str[i];
		}
	}
	sort(s+1,s+n+1);
	for(int i=n;i;i--){
		cout<<s[i];
	}
	return 0;
}
