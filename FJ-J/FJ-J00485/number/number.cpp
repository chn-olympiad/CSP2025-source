#include<bits/stdc++.h>
using namespace std;
//struct h{
//}
int t[15]={0};
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
	for(int i=0;i<s.size();i++) if((int(s[i])>=int('0'))&&(int(s[i])<=int('9'))) t[int(s[i]-'0')]++;	
	for(int i=9;i>=0;i--) for(int j=1;j<=t[i];j++) cout<<i;
	return 0;
} 
