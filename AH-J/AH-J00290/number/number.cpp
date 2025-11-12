#include<bits/stdc++.h>
using namespace std;
string s;
long long ans[10],flag;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int lens=s.size();
	for(int i=0;i<lens;i++)
	{
		if(s[i]>='0'&&s[i]<='9')ans[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--)
    {
		if(ans[i]>0&&i!=0)flag=1;
		while(ans[i]){
			cout<<i;
			ans[i]--;
			if(i==0&&flag==0)break;
		}
	}
	return 0;
}
