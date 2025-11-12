#include<bits/stdc++.h>
using namespace std;
string s;
vector<char> vc;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')vc.push_back(s[i]);
	}
	sort(vc.begin(),vc.end());
	reverse(vc.begin(),vc.end());
	int lenv=vc.size();
	for(int i=0;i<lenv;i++)cout<<vc[i];
	return 0;
}