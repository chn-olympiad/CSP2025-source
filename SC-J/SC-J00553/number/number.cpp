#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int n,m;
int a[N];
string s;
void init(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
}
void collect(){
	cin>>s;
}
void work(){
	n=s.length();
	for(int i=0;i<n;i++){
		if(isdigit(s[i])){
			a[++m]=s[i]-'0';
		}
	}
	sort(a+1,a+m+1);
	for(int i=m;i>=1;i--){
		cout<<a[i];
	}
	
}
void solve(){
	collect();
	work();
}
int main(){
	init();
	solve();
	return 0;
}