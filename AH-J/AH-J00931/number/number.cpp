#include<iostream>
using namespace std;
string s;
bool yet=false;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	char p='9';
	for(int i=9;i>=1;i--){
		for(int j=0;j<s.size();j++){
			if(s[j]==p){
				cout<<p;
				yet=true;
			}
		}
		p--;
	}
	if(yet==false){cout<<"0";return 0;}
	else{
		for(int j=0;j<s.size();j++){
			if(s[j]=='0'){
				cout<<'0';
			}
		}
	}
	return 0;
}
