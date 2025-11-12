#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int j=0;
	int n=s.size();
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0')
			a[++j]=s[i]-'0';
	}
	sort(a+1,a+j+1);
	for(int i=j;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}