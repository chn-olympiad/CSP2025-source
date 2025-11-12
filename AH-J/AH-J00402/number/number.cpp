#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	int cnt=0,n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+1+cnt);
	if(a[cnt]==0){
		cout<<0;
		return 0;
	}
	for(int i=cnt;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
