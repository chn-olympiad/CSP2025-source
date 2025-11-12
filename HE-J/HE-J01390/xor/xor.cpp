#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500001],b,sum=0;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	cin>>b;
	a[1]=b;
	for(int i=2;i<=n;i++){
		cin>>b;
		a[i]=(a[i-1]^b);
	}
	int res=0,ans=1;
	bool f=0;
	while(1){
		f=0;
		for(int i=ans;i<=n;i++){
			if((a[i]^res)==k){
				sum++;
				res^=a[i];
				f=1;
				ans=i;
			}
		}
		ans++;
		if(f==0)res=(res^a[ans-1]);
		if(ans>n)break;
	}
	cout<<sum;
}
