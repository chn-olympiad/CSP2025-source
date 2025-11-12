#include<bits/stdc++.h>
using namespace std;
char s,num[1000050];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i=1;
	while(cin>>s)
	{
		if(s>='0'&&s<='9')
		{
			num[i]=s;
			i++;
		}
	}
	sort(num+1,num+i+1);
	for(int j=i;j>=1;j++) cout<<num[j];
	return 0;
}
