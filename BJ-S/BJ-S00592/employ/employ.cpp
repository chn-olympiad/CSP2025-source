#include<bits/stdc++.h>
using namespace std;
int n,m,a[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			n--;
		}
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		ans*=i,ans%=998244353;
	}
	cout<<ans;
	return 0;
}