#include<bits/stdc++.h>
using namespace std;
const int N=550;
const int mod=998244353;
int n,m;
char s[N];
int c[N];

long long A (int n,int m){//m up n down
	long long ans=1;
	for(int i=1;i<=m;i++){
		ans*=(n-i+1);
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(!c[i])cnt++;
	}
	n-=cnt;
	cout<<A(n,m)<<"\n";
	return 0;
}
