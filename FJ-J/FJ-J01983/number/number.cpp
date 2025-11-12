#include<iostream>
#include<algorithm>
using namespace std;
int n[1000001];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	int cnt=0;
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			cnt++;
			n[cnt]=(int)s[i]-'0';
		}
	}
	sort(n+1,n+cnt+1);
	string ans="";
	for(int i=cnt;i>=1;i--)
		ans+=(char)(n[i]+'0');
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
