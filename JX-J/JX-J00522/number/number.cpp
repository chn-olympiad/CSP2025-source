#include<bits/stdc++.h>
using namespace std;
string s;
string S;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sort(s.begin(),s.end(),greater<char>());
	int l = s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9') S+=s[i];
	}cout<<S;
	return 0;
}
