#include<bits/stdc++.h>
using namespace std;
long long a[2000006],cnt,t;
string s;
map<long long,long long>mp;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	long long len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		mp[s[i]-'0']++,t++;
		if(mp[s[i]-'0']==1)
		{
			cnt++;
			a[cnt]=s[i]-'0';
		}
	}
	if(mp[0]==t){
	printf("0");
	exit(0);
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--)
	{
		//cout<<mp[i]<<endl;
		for(int j=1;j<=mp[a[i]];j++)
		printf("%lld",a[i]); 
	}
	return 0;
} 
