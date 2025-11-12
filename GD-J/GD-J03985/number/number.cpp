#include<bits/stdc++.h>
using namespace std;
char ch[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>ch;
	int n=strlen(ch);
	sort(ch,ch+n);
	for(int i=n-1;i>=0;i--){
		if(ch[i]=='0'&&i==n-1){
			cout<<'0';
			break;
		}
		if(ch[i]<='9'&&ch[i]>='1')
			cout<<ch[i];
		if(ch[i]=='0'&&i!=n-1) cout<<'0';
	}
	return 0;
} 
