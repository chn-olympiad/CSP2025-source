#include<iostream>
#include<set>
using namespace std;
string s;
multiset<int>a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char c:s)if(c>='0'&&c<='9')a.insert(-(c-'0'));
	for(int i:a)cout<<-i;
	return 0;
}
