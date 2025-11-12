#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,k;
int f[N],a[N],sm[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sm[i]=sm[i-1]^a[i];
		f[i]=0;
	}
//	int a=sm[2] ^ sm[2];
//	cout<<a;
	for(int i=1;i<=n;i++){
		
		for(int j=i;j>=1;j--){
			f[i]=max(f[i],f[j]);int www=sm[j-1]^sm[i];
			if(www==k){
				
//				cout<<j<<" "<<i<<" "<<f[i]<<'\n';
				f[i]=max(f[i],f[j-1]+1);break;
			}
		}
		f[i+1]=f[i];
//		cout<<'\n'; 
	}
	cout<<f[n];
	
	return 0;
	}

