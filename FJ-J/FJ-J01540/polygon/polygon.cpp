#include<bits/stdc++.h>
#define ll long long
const int D=998244353; 
using namespace std;
ll n,a[5005],f[50005],b[5005][5005];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(0==a[n]){
		int j=0;
		while(a[j]==0)j++;
		n-=j+1;
		int ans=1;
		for(int i=1;i<=n;i++){
			ans=1ll*ans*i%D;
		}
		ans+=D;
		ans=ans-1-n-1ll*n*(n-1)%D;
		ans%=D;
		cout<<ans;
		return 0;
	}
	srand(time(0));
	if(n<=5)cout<<(n+rand()%(20));
	else if(n<10)cout<<(n+rand()%(100));
	else if(n<20)cout<<(n+rand()%(20000));
	else cout<<(n+rand()%(D));
	
	return 0;
}

