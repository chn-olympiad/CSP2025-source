#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000010];
int top=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++top]=s[i];
		}
	}
	sort(a+1,a+top+1);
	for(int i=top;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 