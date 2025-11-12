#include<string>
#include<cstring>
#include<string.h> 
#include<iostream>
using namespace std;
string s;
int a[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(a[i]--)
			cout<<i;
	return 0;
}
//贪心从大到小输出即可  
