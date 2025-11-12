#include<bits/stdc++.h>
using namespace std;
int n;
string s,ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;	
	n=s.size();
	sort(s.begin(),s.end());
	for(int i=n-1;i>=0;i--){
		if(s[i]>='0'&&s[i]<='9') ans+=s[i];
	}
	cout<<ans;
	return 0;
} 
