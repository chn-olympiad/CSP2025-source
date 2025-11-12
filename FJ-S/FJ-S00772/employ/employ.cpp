#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,m,c[10001],ans=0;
string s;
void dali25_daji01(int x,int y,int cnt){
	
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(m==n){
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				cout<<0;
				return 0;
			}
		}
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'){
				cout<<0;
				return 0;
			}
		}
		if(n==1) cout<<1;
		else cout<<n*(n-1)%N;
	}
	
	return 0;
}