#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int ans[1000005];
int f;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=0;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans[++len]=s[i]-'0';
		}
	}
	sort(ans+1,ans+len+1);
	for(int i=1;i<=len;i++){
		if(ans[i]!=0){
			f=1;
		}
	}
	if(f==0){
		cout<<0<<endl;
		return 0;
	}
	for(int i=len;i>=1;i--){
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
}	
