#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[505],sum;	
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0){
			ans++;
		}
	}
	cout<<ans<<endl;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]=='1'){
			sum++;
		}
	}
	if(sum<m){
		cout<<0;
		return 0;
	}
	if(m==1){
		if(ans==0) ans=1;
		for(int i=1;i<=n-1;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans%998244353;
	}
	else cout<<0;
    return 0;
}


