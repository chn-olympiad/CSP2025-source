#include<bits/stdc++.h>
using namespace std;
string s1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s1;
	for(long long i=0;i<s1.size();++i)if(!(s1[i]>='0'&&s1[i]<='9'))s1.erase(s1.begin()+i),i--;
	sort(s1.begin(),s1.end(),greater<long long>());
	cout<<s1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
