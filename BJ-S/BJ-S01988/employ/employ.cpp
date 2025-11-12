#include<bits/stdc++.h>
using namespace std;

const int N=500,mod=998244353;

int n,m;
char ch;
int s[N+5],c[N+5];

/*int checkA(){
	for(int i=1;i<=n;++i){
		if(s[i]==0){
			return 0;
		}
	}
	return 1;
}

int solveA(){
	int ct=0;
	for(int i=1;i<=n;++i){
		if(c[i]!=0){
			
		}
	}
	return;
}*/

int solve1(){
	for(int i=1;i<=n;++i){
		if(s[i]==0 || c[i]==0){
			return 0;
		}
	}
	long long jc=1;
	for(int i=1;i<=n;++i){
		jc=jc*i%mod;
	}
	return jc;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>ch;
		s[i]=ch-'0';
	}
	for(int i=1;i<=n;++i){
		cin>>c[i];
	}
	/*if(checkA()==1){
		cout<<solveA();
		return 0;
	}*/
	if(m==n){
		cout<<solve1();
		return 0;
	}
	cout<<0;
	return 0;
}
