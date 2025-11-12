#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[100002];
	char n[100002];
	cin>>s;
	for(int i=0;i<1000002;i++){
		if(s[i]='1'||s[i]='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0')
			char n[i]=s[i];
	}
	for(int i=0;i<1000002;i++){
		for(int j=0;i<1000002;j++){
			if(n[i]<n[j])
				swap(n[i],n[j]);
		}
	}
	for(int i=0;i<1000002;i++)
		cout<<n[i];
	return 0;
}
