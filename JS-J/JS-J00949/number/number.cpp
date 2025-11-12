#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int l;
string s;
char ans[N];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();++i)
    {
		if(s[i]>='0'&&s[i]<='9')
			ans[l++]+=s[i];
	}
	stable_sort(ans,ans+l);
	if(ans[l-1]=='0') cout<<0;
	else for(int i=l-1;i>=0;i--) cout<<ans[i];
    return 0;
}
