#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000010],head=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9' and s[i]>='0') a[++head]=s[i]-'0';
	}
	sort(a+1,a+head+1);
	for(int i=head;i>=1;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
