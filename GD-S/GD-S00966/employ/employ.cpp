#include<bits/stdc++.h>
using namespace std;
long long dic[510];
const int maxn=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int cnt=0;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		if(a==0) cnt++;
	}
	dic[0]=1;
	if(n-cnt<m) cout<<0;
	for(int i=1;i<=n-cnt;i++) dic[i]=dic[i-1]*i%maxn;
	
	if(n-cnt>=m){
		cout<<dic[n-cnt];
	}
	return 0;
}
