#include<bits/stdc++.h>
using namespace std;
string s,y,a(100000);
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<1;i++){
		if(a[i]>='0' && s[i]<='9') a[++y]=s[i]-'0';
	}
	sort(a+1,a+y+1);
	
}
