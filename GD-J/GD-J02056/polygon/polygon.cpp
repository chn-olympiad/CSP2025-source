#include<bits/stdc++.h>
using namespace std;
long long a,b[5005],ans=1,i,l,n,m=998244353;
string s;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		for(i=1;i<=n;i++){
			cin>>b[i];
		}
		if(b[1]+b[2]+b[3]>max(b[1],max(b[2],b[3]))*2)cout<<1;
		else cout<<0;
	}
	else{
		for(i=2;i<=n;i++){
			ans=ans*2%m;
		}
		ans=((ans+m)-n*n)%m;
		cout<<ans;
	}
	return 0;
} 
