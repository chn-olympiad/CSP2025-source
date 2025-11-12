#include<bits/stdc++.h>
using namespace std;
string ss="";
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<int(s.size());i++){
		if(s[i]>='0'&&s[i]<='9'){
			ss=ss+s[i];
		}
	}
	sort(ss.begin(),ss.end());
	for(int i=int(ss.size()-1);i>=0;i--){
		cout<<ss[i];
	}
	return 0;
}
