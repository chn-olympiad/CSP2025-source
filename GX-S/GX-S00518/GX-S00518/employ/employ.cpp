#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,s[200009],c[200009],p=998244353;
ll js,ans=1;
char zz;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>zz,s[i]=zz-'0';
	for(int i=1;i<=n;i++){
		 cin>>c[i];
		 if(c[i]=='0') js++;
	}
	if(js>1){
		cout<<0;
		return 0;
	}
	else if(js==0){
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=p;
			//cout<<ans<<endl;
		}
		cout<<ans;
		return 0;
	}
	else{
		for(int i=n-1;i>=1;i--){
			ans*=i;
			ans%=p;
			//cout<<ans<<endl;
		}
		cout<<ans;
		return 0;
	}
			
	return 0;
}
