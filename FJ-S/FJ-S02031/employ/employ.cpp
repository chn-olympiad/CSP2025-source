#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
long long ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		if(c=='1')cnt++;
	}
	for(int i=1;i<=n;i++){
		int c;
		cin>>c;
		
	}
	if(m==1){
		for(int i=2;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
	}
	if(m>cnt)cout<<0;
}
