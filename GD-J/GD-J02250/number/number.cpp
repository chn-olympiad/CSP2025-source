#include<bits/stdc++.h>
using namespace std;
string s,r="";int a[10],l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]-'0'>=0&&s[i]-'0'<10){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			r+=(i+'0');
		}
	}
	cout<<r;
	fclose(stdin);
	fclose(stdout);
}
