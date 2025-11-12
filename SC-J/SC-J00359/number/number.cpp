#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int a[10];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(48<=s[i] and s[i]<=57){
			int c=s[i]-48;
			a[c]+=1;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
}