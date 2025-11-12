#include<bits/stdc++.h>
using namespace std;
string s,ans;
int cnt[256];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		cnt[int(s[i])]++;
	}
	for(int i='9';i<='1';i++){
		for(int j=1;j<=cnt[i];j++){
			ans+=char(i);
		}
	}
	cout<<ans;
	return 0;
}
