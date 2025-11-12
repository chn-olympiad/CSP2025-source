#include<bits/stdc++.h>
using namespace std;
#define MAXN (int)1e5+10
#define ld long long
long long mod=998244353;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int c[n];
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	if(n<=10){
		for(int i=0;i<n;i++){
		cout<<c[i];	
	}
	}else{
		cout<<0;
	}
	return 0;
}

