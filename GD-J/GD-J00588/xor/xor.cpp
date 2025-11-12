#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long  n,k,a[N];
int tot,tot1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)tot++;
		if(a[i]==0)tot1++;
	}
	if(tot==n){
		if(k==0){
			cout<<n/2<<endl;
			return 0;
		}else if(k==1){
			cout<<n<<endl;
			return 0;
		}else{
			cout<<0<<endl;
			return 0;
		}
	}
	if(tot+tot1==n){
		if(k==1){
			cout<<tot<<endl;
			return 0;
		}else if(k==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0)ans++;
				else if(a[i]==1&&a[i+1]==1) a[i+1]=0;
			}
			cout<<ans<<endl;
			return 0;
		}else{
			cout<<0<<endl;
			return 0;
		}
	}
	cout<<1<<endl;
	return 0;
} 
