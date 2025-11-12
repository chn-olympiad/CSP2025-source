#include<iostream>
#include<algorithm>
using namespace std;
short l[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int index=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if('0'<=s[i] && s[i]<='9')
			l[index++]=s[i]-'0';
	sort(l,l+index);
	for(int i=index-1;i>=0;i--) cout<<l[i];
}
