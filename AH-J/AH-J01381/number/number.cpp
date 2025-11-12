#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<(int)s.size();i++)
		if(s[i]>='0'&&s[i]<='9') n.push_back(s[i]-'0');
	sort(n.begin(),n.end());
	for(int i=n.size()-1;i>=0;i--){
		cout<<n[i];
	}
	cout<<endl;
	return 0;
}
