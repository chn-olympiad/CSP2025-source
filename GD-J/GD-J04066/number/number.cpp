#include<bits/stdc++.h>
using namespace std;
string s;
string st;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]>='0'&&s[i]<='9') st+=s[i];
	}
	sort(st.begin(),st.end());
	reverse(st.begin(),st.end());
	cout<<st;
	return 0;
}
