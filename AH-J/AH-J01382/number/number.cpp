#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
string s;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	s="";
	for(int i=9;i>=0;i--){
		while(a[i]!=0){
			s+=(char(i+'0'));
			a[i]--;
		}
	}
	cout<<s;
}
