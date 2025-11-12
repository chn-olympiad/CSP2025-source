#include<bits/stdc++.h>
using namespace std;
string s,ans;
vector<char>a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a.push_back(s[i]);
		}
	}
	sort(a.begin(),a.end());
	for(int i=a.size()-1;i>=0;i--){
		if(a[i]=='0'){
			if(ans.size()>0&&ans[0]!='0'){
				ans+=a[i]; 
			}
			if(ans.size()==0){
				ans+=a[i];
			}
		}
		else{
			ans+=a[i];
		}
	}
	cout<<ans;
	return 0;
} 
