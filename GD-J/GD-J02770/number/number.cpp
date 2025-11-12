#include<bits/stdc++.h>
#define ll long long
using namespace std;
int num[15],len;
string s;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
getline(cin,s);
len=s.size();
for(int i=0;i<len;i++)
	if('0'<=s[i]&&s[i]<='9') num[s[i]-'0']++;
for(int i=9;i>=0;i--)
{
	for(int j=1;j<=num[i];j++)
		printf("%d",i);
}
fclose(stdin);
fclose(stdout);
	return 0;
}
