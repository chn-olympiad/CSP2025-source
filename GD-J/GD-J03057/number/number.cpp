#include<bits/stdc++.h>
using namespace std;
bool cmp(char ababa,char babab){
	return ababa>babab;
}
int main(){
	ios::sync_with_stdio(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string S__S;char C__C;
	while(cin>>C__C){
		if(isdigit(C__C))S__S+=C__C;
	}
	sort(S__S.begin(),S__S.end(),cmp);
	cout<<S__S;
}
