#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],x=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9') a[x++]=s[i]-'0';
	}sort(a,a+x); 
	for(int i=x-1;i>=0;i--)
		cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}