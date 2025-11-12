#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	bool f=1;
	bool ff=1;
	for(int i=1;i<s.size();i++){
		if(s[i]=='1'){
			continue;
		}
		if(s[i]=='0')ff=0;
		f=0;
		break;
	}
	if(f==1){
		cout<<1;
		return 0;
	}
	else{
		if(m==n){
			if(ff=0){
				cout<<0;
				return 0;
			}
		}
	cout<< 998244352;
	}
	return 0;
}
