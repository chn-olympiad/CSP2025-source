#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
string s;
int n[15],l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++)
		if(s[i]>='0' && s[i]<='9')
			n[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=0;j<n[i];j++)
			printf("%d",i);
	return 0;
}
