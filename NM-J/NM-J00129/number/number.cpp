#include<bits/stdc++.h>
using namespace std;
string s;
long long d[10000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.length();
	int j=1;
	for(long long i=0;i<=len-1;i++)
	    if(s[i]>='0'&&s[i]<='9') {d[j]=int(s[i]);j++;}
	sort(d+1,d+j+1);
	string ans;
	for(long long i=j;i>=0;i--)
	    ans+=char(d[i]); 
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
