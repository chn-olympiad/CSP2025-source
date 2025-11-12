#include<bits/stdc++.h>
using namespace std;
int b[100009];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,a="";
	long long x=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			x++;
			b[x]=s[i]-'0';
		}
	}
	sort(b+1,b+x+1);
	for(int i=x;i>=1;i--){
		cout<<b[i];
	}
}