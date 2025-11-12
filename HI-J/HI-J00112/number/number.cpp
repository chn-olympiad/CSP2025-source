#include<bits/stdc++.h>
using namespace std;
string s;
char x[100010];
long long int len=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			x[len++]=s[i];
		}
	}
	
	sort(x,x+len);
	for(int i=0;i<len;i++){
		cout<<x[len-i-1];
	}
	return 0;
}
