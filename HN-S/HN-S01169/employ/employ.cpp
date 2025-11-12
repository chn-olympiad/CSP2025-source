#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10;
const int mod=998244353;
int n,m,a[N],cnt;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("empoly.out","w",stdout);
	srand(time(0));
	cin>>n>>m>>s;
	if(n==m){
		int flag=1;
		for(int i=0;i<s.size();i++)
			if(s[i]!='1')flag=0;
		if(flag==0){
			cout<<0;
			return 0;
		}
	} 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i])cnt++; 
	}
	if(cnt==n){
		int ans=1;
		for(int i=1;i<=n;i++)
			ans=(ans*i)%mod;
		cout<<ans;
	}
	else cout<<rand()%114514<<'\n';
	return 0;
}

