#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,t;
	cin>>s;
	for(char i:s){
		if(isdigit(i))t+=i;
	}
	sort(t.begin(),t.end());
	reverse(t.begin(),t.end());
	cout<<t;
	return 0;
}
