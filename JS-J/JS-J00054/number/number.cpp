#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int ans[N],cnt;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(unsigned int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			ans[++cnt]=s[i]-'0';
	sort(ans+1,ans+1+cnt);
	if(ans[cnt]==0)printf("0");
	else for(int i=cnt;i>=1;i--)printf("%d",ans[i]);
	printf("\n");
	return 0;
}
