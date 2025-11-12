#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	long long ans=0;
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int c[502],a=0,b=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			b++;
		}else{
			a++;
		}
	}
	if((n-b)<m){
		cout<<0<<endl;
		return 0;
	}
	else if((n-b)==m){
		cout<<1<<endl;
		return 0;
	}
	
	else{
		for(int i=1;i<=n;i++){
			if(i==1){
				ans=n;
				continue;
			}
			ans=(ans*i)%998244353;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
