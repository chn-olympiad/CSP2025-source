#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,m,c[505],ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++) cin>>c[i];
	if(s.find('0')==-1){
		for(int i=n;i>=1;i--){
			ans=(ans*i)%N;
		}
		cout<<ans;
	}
	if(n==m){
		if(s.find('0')!=-1) cout<<0;
		for(int i=n;i>=1;i--){
			ans=(ans*i)%N;
		}
		cout<<ans;
	}
	return 0;
} 
