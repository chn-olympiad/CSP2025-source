#include<bits/stdc++.h>
using namespace std;
int n,m,b[10010];
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string a;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		
	}
	int flag=1;
	for(int i=0;i<n;i++){
		if(a[i]!=1){
			flag=0;
			break;
		}
	}
	if(flag==1){
		for(int i=1;i<=m;i++){
			ans=((ans%998244353)*i)%998244353;
		}
		cout<<ans;
	}
	cout<<0;
}
// Ren5Jie4Di4Ling5%
