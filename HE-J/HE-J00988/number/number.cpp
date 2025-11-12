#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>s;
	int len=s.size(),n[len+10],ans=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans++;
			n[ans]=s[i]-'0';
		}
	}sort(n+1,n+ans+1,cmp);
	for(int i=1;i<=ans;i++){
		cout<<n[i];
	}
	return 0;
}
