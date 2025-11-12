#include<bits/stdc++.h>
using namespace std;
string s;
int c[1000005],cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			c[++cnt]=s[i]-'0';
	sort(c+1,c+1+cnt);
	for(int i=cnt;i>=1;i--)
		cout<<c[i];
	cout<<'\n';
	return 0;
}
