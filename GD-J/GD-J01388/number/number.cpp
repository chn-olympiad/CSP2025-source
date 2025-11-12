#include<bits/stdc++.h>
using namespace std;
string s;
long long a[15];
bool v;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>s;
	for(int i=0;i<s.size();i++)
	    if(s[i]>='0'&&s[i]<='9')
	        a[s[i]-48]++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=a[i];j++){
			cout<<i;
			if(i==0&&!v)
			    return 0;
			v=true;
		}
	return 0;
} 
