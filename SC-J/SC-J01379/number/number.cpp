#include<bits/stdc++.h>
using namespace std;
string s;
int a[11];
int main(){
//  froepen
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
//  froepen("number.in","r",stdin);
//	froepen("number.out","w",stdout);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			int a1=s[i]-'0';
		    a[a1]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]!=0){
			cout<<i;
			a[i]--;
		}
	}
	return 0;
} 