#include<bits/stdc++.h>
using namespace std;
string cmp[10];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size(),x;
	for(int i=0;i<l;i++){
		x=s[i]-'0';
		if(x>=0&&x<=9)cmp[x]+=s[i];
	}
	for(int i=9;i>=0;i--){
		cout<<cmp[i];
	}
	return 0;
}
