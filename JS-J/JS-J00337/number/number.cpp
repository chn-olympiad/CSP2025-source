#include <bits/stdc++.h>
using namespace std;
string s;
char n[1000006];
int j=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9'){
			n[j]=s[i];
			j++;
		}
	}
	sort(n,n+j,greater<int>());
	for(int i=0;i<j;i++)
	{
		cout<<n[i];
		}
	return 0;
}
