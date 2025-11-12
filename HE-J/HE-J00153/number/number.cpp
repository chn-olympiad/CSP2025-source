#include<bits/stdc++.h>
using namespace std;
	int a[1000008];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int y=0;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[y]=s[i]-'0';
			y++;
		}
	}
	sort(a,a+y);
	for(int i=y-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 
