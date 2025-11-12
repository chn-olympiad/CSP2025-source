#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
string s;
int a[100];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int x=s[i]-'0';
			a[x]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]>0){
			for(int j=1;j<=a[i];j++)
			cout<<i;
		}
	}
	return 0;
}
