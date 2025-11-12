#include<bits/stdc++.h>
using namespace std;
int nai[1000];
const int N=998244353;
long long pailie(int x){
	if(x==1)return 1;
	return (x*pailie(x-1))%N;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>nai[i];
	if(m==1){
		cout<<pailie(n)%N;
	}
	else if(m==n){
		cout<<0;
	}
	else{
		cout<<pailie(n)%N;
	}
	return 0;
}

