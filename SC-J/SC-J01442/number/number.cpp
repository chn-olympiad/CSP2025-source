#include <bits/stdc++.h>
using namespace std;
const int N=1e6+3;
string s;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<N;i++)
		a[i]=-1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
			a[i]=int(s[i])-48;
	}
	sort(a,a+s.size());
	for(int i=s.size()-1;i>=0;i--)
	{
		if(a[i]!=-1)
			cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}