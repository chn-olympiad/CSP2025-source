#include<bits/stdc++.h>
using namespace std;
int n[1000002],j;
string s,ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i = 0;i<s.size();i++){
		int m=(int)s[i]-48;
		if(m>=0 && m<=9){
			n[j++]=m;
		}
	}
	sort(n,n+j);
	for(int i = j;i>0;i--){
		ans+=(char)(n[i-1]+48);
	}
	cout<<ans;
	return 0;
}
