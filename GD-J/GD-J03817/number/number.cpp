#include<bits/stdc++.h>
using namespace std;
string s;
char ans[1000005];
int sl;
bool cmp(char ai,char bi){return ai>bi;}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++) if(s[i]>='0'&&s[i]<='9') ans[++sl]=s[i];
	sort(ans+1,ans+sl+1,cmp);
	for(int i=1;i<=sl;i++) printf("%c",ans[i]);
	return 0;
}
