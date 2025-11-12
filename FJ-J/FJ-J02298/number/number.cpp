#include<bits/stdc++.h>
using namespace std;
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int a[1100];
int main(){
	int mx=0,q;
	string s,b=" ";
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
			b+=s[i]; 
		}
	}
	
	for(int i=1;i<b.size();i++)a[i]=-1;
	for(int i=1;i<b.size();i++)a[i]=int(b[i])-'0';
	q=b.size();
	sort(a+1,a+q+1);
	for(int i=q;i>1;i--){
		cout<<a[i];
	}
	
}
