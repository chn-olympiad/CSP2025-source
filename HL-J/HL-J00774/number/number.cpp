#include<bits/stdc++.h>
using namespace std;
string s;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char c;
	while(cin>>c){
		if(c>='0'&&c<='9')
		s+=c;
	}
	sort(s.begin(),s.end(),cmp);
	cout<<s;
	return 0;
}

