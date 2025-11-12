#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
long long n,m,b[505],pan,ans=2;
char a[505];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=0;i<n;i++){
		b[i+1]=a[i];
		if(b[i+1]==0)pan++;
	}
	if(pan==0){
		ans--;
		sort(b+1,b+1+n);
		int n1=n;
		for(int i=0;i<m;i++){
			ans=(ans%Mod)*(n1%Mod)%Mod;
			n1--;
		}
		cout<<ans;
	}
	else cout<<ans;
	return 0;
} 
