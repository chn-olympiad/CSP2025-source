#include<iostream>
using namespace std;
#define fo(i,begin,end) for(int i=begin;i<=end;i++)
int cnt[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	fo(i,0,s.size()-1) if(s[i]>='0'&&s[i]<='9') cnt[s[i]-'0']++;
	for(int i=9;i>=0;i--) fo(j,1,cnt[i]) cout<<i;
	return 0;
}