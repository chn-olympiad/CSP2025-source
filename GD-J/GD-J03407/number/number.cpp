#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
string s;
vector<int> vt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<'0'||s[i]>'9')continue;
		vt.push_back(s[i]-'0');
	}
	sort(vt.begin(),vt.end());
	for(int i=vt.size()-1;i>=0;i--)
		printf("%d",vt[i]);
	return 0;
}
 
