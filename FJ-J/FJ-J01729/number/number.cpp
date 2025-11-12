#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int a[10]={0,0,0,0,0,0,0,0,0,0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int x=s[i]-'0';
			a[x]++;
		}
	}
	string ans;
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			ans+=(i+'0');
		} 
	}
	cout<<ans<<endl;
	return 0;
}
