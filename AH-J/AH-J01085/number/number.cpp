#include <bits/stdc++.h>
using namespace std;
string s;
long long a[15],vis;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
	}
	for(int i=9;i>=1;i--){
		if(a[i]) vis=1;
		while(a[i]--) cout<<i;
	}
	if(!vis) cout<<"0";
	else{
		while(a[0]--) cout<<"0";
	}
	return 0;
}
