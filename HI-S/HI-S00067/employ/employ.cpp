#include<bits/stdc++.h> 
using namespace std;
int n,m,c[505],ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int n1=n;
	for(int i=1;i<=n;i++){
		if(c[i]==0)n1--;
	}
	if(n1<m){
		cout<<0;
		return 0;
	}
	for(int i=n1;i>0;i--){
		ans*=i;
		ans%=998244353;
	}
	cout<<ans;
}
