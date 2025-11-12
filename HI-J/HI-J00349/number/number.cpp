#include<bits/stdc++.h>
using namespace std;
int a[1000100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	int c=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[++c]=s[i]-'0';
	}
	sort(a+1,a+1+c,greater<int>());
	for(int i=1;i<=c;i++) cout<<a[i];

 return 0;
}

