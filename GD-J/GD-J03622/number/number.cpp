#include<iostream>
#include<algorithm>
using namespace std;
int l[1000055],len=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	string s;cin>>s;
	for(int i=0;i<s.size();i++)if(s[i]>='0'&&s[i]<='9'){l[len]=(s[i]-'0');len++;}
	sort(l,l+len);
	for(int i=len-1;i>=0;i--)cout<<l[i];
	return 0;
} 
