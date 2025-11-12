#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	sort(s.begin(),s.end());
	reverse(s.begin(),s.end());
	for (int i=0;i<l;i++){
		if (isdigit(s[i])){
			cout<<s[i];
		}
	}
	return 0;
}
