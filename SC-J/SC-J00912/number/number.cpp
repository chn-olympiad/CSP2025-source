#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
string s,f;
vector<char> ts;
void putin()
{
	cin>>s;	
}
bool cmp(char a,char b){return a>b;}
void chuli()
{
	for(char v:s)
		if(v>='0'&&v<='9') ts.push_back(v);
	sort(ts.begin(),ts.end(),cmp);
}
void putout(){
	for(char v:ts) cout<<v;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	putin();
	chuli();
	putout();
	return 0;
}