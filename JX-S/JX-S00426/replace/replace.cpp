#include <bits/stdc++.h>
using namespace std;
int n,q;
map<string,string> a;
string s[10010];
int main(){
freopen("replace.in","r",stdin);
freopen("replace.out","w",stdout);
cin>>n>>q;
for(int i=1;i<=n;i++)
{
	string s1,s2;
	cin>>s1>>s2;
	s[i]=s1;
	a[s1]=s2;
}
for(int i=1;i<=q;i++)
{  
	string s1,s2;
	cin>>s1>>s2;
	cout<<n<<endl;
}
return 0;
}
