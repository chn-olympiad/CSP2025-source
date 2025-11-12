#include<map>
#include<iostream>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	map<char,long long> mp;
	string s;
	cin>>s;
	for(char i:s) if('0'<=i && i<='9') mp[i]++;
	for(char i='9';i>='0';i--) for(int j=1;j<=mp[i];j++) cout<<i;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
