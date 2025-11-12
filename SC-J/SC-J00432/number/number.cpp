#include<bits/stdc++.h>
using namespace std;
vector<char>a;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9')a.push_back(s[i]);
	}
	sort(a.begin(),a.end());
	int l=a.size();
	for(int i=l-1;i>=0;i--)cout<<a[i];
	return 0;
}