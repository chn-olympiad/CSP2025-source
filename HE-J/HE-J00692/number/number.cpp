#include<bits/stdc++.h>
using namespace std;
string s;
char c[2000005];
long long a=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
		c[a]=s[i];
		a++;}
	} 
	sort(c+1,c+a+1);
	for(int i=a;i>=1;i--) cout<<c[i];
	return 0;
}
