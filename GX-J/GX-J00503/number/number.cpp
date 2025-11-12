#include<bits/stdc++.h>
using namespace std;
string s,t;
long long mx=-100000000,cnt,ans=1,q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			t[i]=s[i];
		}	
	}	
	
	for(int i=0;i<t.size();i++){
		if(t[i]>mx){
			mx=t[i];
			cout<<int(mx);
			mx=-100000000;
		}
	}
	return 0;

}
