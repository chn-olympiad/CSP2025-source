#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#define intt long long
#define intu unsigned long long
using namespace std;
const int Imax=0x7fffffff;
const long long LLmax=0x7fffffffffffffff;
string s,ans;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char i:s) if('0'<=i&&i<='9')ans.push_back(i);
	sort(ans.begin(),ans.end());reverse(ans.begin(),ans.end());
	cout<<ans;
	return 0;
}
