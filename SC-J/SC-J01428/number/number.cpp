#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int a[N],top;
string s;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i)
		if(s[i]>='0'&&s[i]<='9')
			a[++top]=s[i]-'0';
	sort(a+1,a+1+top,greater<int>());
	for(int i=1;i<=top;++i)
		cout<<a[i];
	return 0;
}
