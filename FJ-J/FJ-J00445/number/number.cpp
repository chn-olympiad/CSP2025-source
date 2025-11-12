#include<iostream>
using namespace std;
string s,ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int k=9;k>=0;k--){
		for(int i=0;i<=s.size();i++){
			if(s[i]==char(k+'0')){
				ans+=s[i];
			}
		}
	}
	cout<<ans;
	return 0;
} 
