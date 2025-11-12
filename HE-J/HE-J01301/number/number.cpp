#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	string ttt;
	for(auto i:s){
		if(i>='0'&&i<='9')ttt+=i;
	}sort(ttt.begin(),ttt.end());
	for(auto i=ttt.rbegin();i!=ttt.rend();i++){
		cout<<*i;
	}
	
	return 0;
}
