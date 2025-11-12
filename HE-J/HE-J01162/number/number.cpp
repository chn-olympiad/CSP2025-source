#include <bits/stdc++.h>
using namespace std;
string s;
long long a[101];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>=48&&s[i]<=57)
		{
			a[s[i]-48]++;
		}
	}
	for(int j=9;j>=0;j--)
	for(int i=1;i<=a[j];i++){
		cout<<j;
	}
	return 0;
} 


