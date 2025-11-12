#include<bits/stdc++.h>
using namespace std;
int n,cnt[256];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	n=s.length();
	for(int i=0;i<n;i++){
		cnt[(int)(s[i])]++;
	}
	for(int i='9';i>='0';i--){
		for(int j=1;j<=cnt[i];j++){
			cout<<(char)(i);
		}
	}
	return 0;
}
