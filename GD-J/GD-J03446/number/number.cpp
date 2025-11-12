#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,res;
	cin>>s;
	for(char c:s)
		if(c>='0'&&c<='9')res+=c;;
	sort(res.begin(),res.end());
	reverse(res.begin(),res.end());
	cout<<res;
	return 0;
} 
