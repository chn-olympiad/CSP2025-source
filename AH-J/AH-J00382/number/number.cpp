#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	int t[10]={0},l;
	string s;
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++)
		if(s[i]<='9' && s[i]>='0') t[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(t[i]--) cout<<i;
	cout<<endl;
	return 0;
}
