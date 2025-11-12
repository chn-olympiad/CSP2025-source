#include<bits/stdc++.h>
using namespace std;int s[1000],c[1000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);char ab;
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ab;
		s[i]=ab-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+n+1);int x=n;
	for(int i=1;i<=n;i++){
		if((i-1)>=c[i]){
			x--;
		}else{
			break;
		}
	}
	if(x>=m){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans*=(n-i+1);ans%=998244353;
		}cout<<ans;
	}else{
		cout<<0;
	}
	return 0;
}