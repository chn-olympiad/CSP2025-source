#include<bits/stdc++.h>
using namespace std;
const int T=1e6+10;
int a[T];
int x;
int t;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	x=s.size();
	for(int i=0;i<x;i++){
		if(s[i]>=48&&s[i]<=57){
			a[t]=s[i]-48;
			t++;
		}
	}
	sort(a,a+t);
	reverse(a,a+t);
	if(a[0]==0){
		cout<<'0';
		return 0;
		}
	
		for(int i=0;i<t;i++){
			cout<<a[i];
		}
	return 0;
}
