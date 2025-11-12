#include<bits/stdc++.h>
using namespace std;
string s;
long long a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
		{
			a[s[i]-'0']++;
		 } 
	}
	for(int i=9;i>=0;i--)
	{
		while(a[i])
		{
			printf("%d",i);
			a[i]--;
		}
	}
	return 0;
}//#Shang4Shan3Ruo6Shui4
