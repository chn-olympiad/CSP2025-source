#include <iostream>
#define ll long long
#define MAXX 500005
using namespace std;

ll a[MAXX],Xor[MAXX],n,k,ans,m;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	Xor[1]=a[1];
	for(ll i=2;i<=n;i++){
		Xor[i]=Xor[i-1]^a[i];
	}

	/*for(int i=1;i<=n;i++) cout<<Xor[i]<<' ';
	cout<<endl;*/
	
	for(int i=1;i<=n;i++){
		if(Xor[i]==k) ans++;
	}
	for(ll l=2;l<=n;l++){
		for(ll q=1;q<l;q++){
			m=Xor[l]^Xor[q];
			if(m==k) ans++;
		}
	}
	cout<<ans;
	return 0;
}
