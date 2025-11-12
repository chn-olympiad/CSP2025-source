#include<bits/stdc++.h>
using namespace std;
int nums_[14]={0,0,0,0,0,0,0,0,0,0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i]>=48&&s[i]<=57)
			nums_[s[i]-48]++;
	}
	for(int x=9;x>=0;x--)
		for(int i=1;i<=nums_[x];i++)
			cout << x;
	return 0;
}