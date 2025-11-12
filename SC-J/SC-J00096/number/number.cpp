#include<bits/stdc++.h>
using namespace std;
int x,y,b[1000005];
string s;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int i=0 ;i<s.size();i++)
	if(s[i]+'0'>=0 &&s[i]+'0'<=9){
		y++;
		b[y]=s[i]-48;
		sort(b+1,b+1+y);	
	}		
	for(int i=y;i>=1;i--)
	cout<<b[i];
	return 0;
}