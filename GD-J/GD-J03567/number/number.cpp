#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
int a[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,ans;
	long long sum=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<='9'&&s[i]>=0)a[s[i]-'0']++,sum++;
	}
	//for(int i=9;i>=0;i--)cout<<a[i]<<endl;
	//cout<<sum<<endl;
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<a[i];j++)ans+=char(i+'0');
		//sum-=a[i];
		
		//cout<<ans<<endl;
	}
	cout<<ans;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
