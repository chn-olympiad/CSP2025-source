#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N];
int c;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a[c]=s[i]-'0';
			c++;
		}
	}
	sort(a,a+c);
	if(a[c-1]==0) cout<<0;
	else{
		for(int i=c-1;i>=0;i--){
			cout<<a[i];
		}
	}
	return 0;
 } 
