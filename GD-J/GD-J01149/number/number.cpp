#include<bits/stdc++.h>
using namespace std;
string s,ans;
int a[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a[s[i]-'0']+=1;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]>0){
			for(int j=0;j<a[i];j++){
				char b=i+'0';
				ans=ans+b;
				cout<<ans<<endl;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
 
