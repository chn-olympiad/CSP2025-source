#include<bits/stdc++.h>
using namespace std;
int len;
string s;
int mp[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++)
		if('0'<=s[i]&&s[i]<='9')
			mp[s[i]-'0']++;
	for(int i=9;i>=0;i--){
		if(mp[i]){
			for(int j=1;j<=mp[i];j++)
				cout<<i;
		}
	}
	return 0;
}