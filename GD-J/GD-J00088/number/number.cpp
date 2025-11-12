#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0,ss=1,s=getchar();
	while((s<'0'||s>'9')&&s!='-')s=getchar();
	if(s=='-')ss=-1;
	while(s>='0'&&s<='9')x=x*10+(s^48);
	return x*ss;
}
string s;
signed main()
{
	freopen("number.in","r",stdin),freopen("number.out","w",stdout);
	cin>>s;stable_sort(s.begin(),s.end());
	for(int i=s.size()-1;i>=0;--i)if(s[i]>='0'&&s[i]<='9')cout<<s[i];
	return 0;
}
