#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	feropen("number.in","r",stdin);
	feropen("number.out","w",stdout);
	string s;
	cin>>s;
	int x=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			x++;
			a[x]=s[i]-'0';
		}
	}
	sort(a+1,a+x+1);
	for(int i=x;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
