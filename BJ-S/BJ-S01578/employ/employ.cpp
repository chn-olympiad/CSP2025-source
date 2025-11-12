#include <bits/stdc++.h>
using namespace std;
int n, m, c[502], cnt;
bool s[502];
char t;
int main(){
	freopen("employ.in", "r", stdin):
	freopen("employ.out", "w", stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>t;
		s[i]=t-'0';
		cnt+=s[i];
	}
	if(cnt<m){
		cout<<0;
	}
	else{
		cout<<1;
	}
}