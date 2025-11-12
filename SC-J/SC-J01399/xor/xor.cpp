#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,k,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==1){
		for(int i=1;i<=n;i++){
			int a;
			cin>>a;
			if(a)sum++;
		}
		cout<<sum;
		return 0;
	}else{
		ll ans=0;
		for(int i=1;i<=n;i++){
			int a;
			cin>>a;
			if(a)sum++;
			else
				ans+=sum/2+1,sum=0;
		}
		cout<<ans+sum/2;return 0;
	}
	return 0;
}
