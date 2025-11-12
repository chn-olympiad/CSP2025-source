#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char st[N];vector<int>G;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",st+1);int len=strlen(st+1);
	for(int i=1;i<=len;i++)if('0'<=st[i]&&st[i]<='9')G.push_back(st[i]-48);
	sort(G.begin(),G.end());
	for(int i=G.size()-1;i>=0;i--)printf("%d",G[i]);
	return 0;
}
