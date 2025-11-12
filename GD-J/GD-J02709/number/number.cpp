#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],gs;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		int sz=s[i]-48;
		if(sz>=0&&sz<=9){
			a[gs]=sz;
			gs++;
		}
	}
	sort(a,a+gs);
	if(a[1]==0){
		cout<<0;
		return 0;
	}
	for(int i=gs-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 
