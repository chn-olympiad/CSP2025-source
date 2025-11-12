#include<bits/stdc++.h>
#define ll long long

using namespace std;
string s;
int a[1000010],cnt;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]>='0'&&s[i]<='9') a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+1+cnt);
	if(a[cnt]==0) {cout<<0;return 0;}
	for(int i=cnt;i>0;i--){
		cout<<a[i];
	}
	
	return 0;
}
