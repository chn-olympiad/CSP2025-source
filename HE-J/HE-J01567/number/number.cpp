#include<bits/stdc++.h>
using namespace std;
string s;
int num[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>s;
	for(int i=0;i<=9;i++) num[i]=0;
	for(int i=0;i<(int)s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			num[int(s[i]-'0')]++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=num[i];j++)
			cout<<i;
	return 0;
}
