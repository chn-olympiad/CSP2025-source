#include<bits/stdc++.h>
using namespace std;
const int N=10;
int t[N];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>s;
	for(int i=0;i<=s.size()-1;++i){
		if(48<=s[i] and s[i]<=57){
			t[int (s[i])-'0']++;
		}
		
	}
	for(int i=9;i>=0;--i){
		if(t[i]>0){
			for(int j=1;j<=t[i];++j)
			cout<<i; 
		}
	}
	return 0;
}