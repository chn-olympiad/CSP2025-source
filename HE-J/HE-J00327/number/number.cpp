#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	char a[100001];
	int g=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
			g++;
			a[g]=s[i];
		}
	}
	sort(a+1,a+g+1);
	for(int i=g;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}

