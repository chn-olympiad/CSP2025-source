#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N],t;
bool f;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(unsigned int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[++t]=s[i]-'0';
	}
	sort(a+1,a+t+1);
	for(int i=t;i>=1;i--){
		if(f==false&&a[i]!=0) f=true;
		if(f==true) cout<<a[i]; 
	}
	return 0;
}
