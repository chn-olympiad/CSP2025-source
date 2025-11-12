#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i = 1;i<=s.size();i++){
		if(s.size()<=1){
			cout<<s<<endl;
			return 0;
		}
		if(s.size()>1){
			cout<<s<<endl;
		}
	}
	
	return 0;
}
