#include<bits/stdc++.h>
using namespace std;
string s;
int a[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i]))
			a[s[i]-48]++;
	}
	for(int i=9;i>=0;i--){
		while(a[i]>=1){
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}
