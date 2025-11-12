#include <bits/stdc++.h>
using namespace std;
char s[11000000];
int a[11000000],fla;
int main(){
	freopen("number.in", "r",  stdin );
	freopen("number.out", "w", stdout );
	cin>>s;
	int len=strlen(s);
	while(len--){
		if(int(s[len])>=48&&int(s[len]<=57)){
			a[++fla]=s[len]-'0';
		}
		
	}
	sort(a+1,a+fla+1);
	if(a[fla]==0){
		cout<<0;
		return 0;
	}
	for(int i=fla;i>=1;i--){
		cout<<a[i];
	} 
	return 0;
}
