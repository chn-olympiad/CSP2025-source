#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	bool t=true;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			t=false;
		}
	}
	cout<<t<<endl;
	return 0;
}
