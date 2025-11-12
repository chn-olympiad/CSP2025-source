#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s,ans; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sort(s.begin(),s.end());
	for(int i=0;i<s.size();i++){
		if(s[i]<'0'||s[i]>'9'){
			break;
		}else{
			ans+=s[i];
		}
	}
	for(int i=ans.size()-1;i>=0;i--){
		cout<<ans[i];
	}
	
	return 0;
} 