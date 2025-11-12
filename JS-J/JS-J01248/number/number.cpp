#include <bits/stdc++.h>
using namespace std;
string s,ans[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int siz=s.size();
	for (int i=0;i<siz;i++){
		if (s[i]>='0'&&s[i]<='9')
		  ans[(s[i]-'0')]+=s[i];
	}
	for (int i=9;i>=0;i--)
	  cout<<ans[i]; 
	return 0;
}
