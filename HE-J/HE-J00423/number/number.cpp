#include<bits/stdc++.h>
using namespace std;
char x[1001000];
int m=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			x[m]=s[i];
			m++;
		}
	}
	sort(x+1,x+m+1);
	for(int i=m;i>=1;i--){
		if(x[i]=='0'&&i==m){
			cout<<0;
			return 0;
		}
		cout<<x[i];
	}
	return 0;
}
