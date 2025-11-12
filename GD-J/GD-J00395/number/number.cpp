#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	char s;
	vector<int> k;
	while(cin>>s)if(s>='0'&&s<='9')k.push_back(s-'0');
	sort(k.begin(),k.end());
	for(int i=k.size()-1;i>-1;i--)cout<<k[i];
	return 0;} 
