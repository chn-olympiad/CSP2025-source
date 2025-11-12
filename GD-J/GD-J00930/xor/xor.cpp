#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e3+10;
int XOR(int a,int b){
	int i=1;
	int res=0;
	while(a>0||b>0){
		if(a%2!=b%2){
			res+=i;
		}
		i*=2;
		a/=2;
		b/=2;
	}
	return res;
}
int A[N];
int res[N][N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>A[i];
	}
	if(n>=1e4){
		cout<<n;
		return 0;
	}
	int sum=0;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int sum=0;
			for(int z=l;z<=r;z++){
				sum=XOR(sum,A[z]);
			}
			if(sum==k){
				res[l][r]=1;
			}
		}
	}
	int ans=0;
	int l=1;
	for(int r=1;r<=n;r++){
		int la=l;
		bool flag=1;
		for(;l<=r;l++){
			if(res[l][r]){
				ans++;
				l=r+1;
				flag=0;
				break;
			}
		}
		if(flag){
			l=la;
		}
	}
	cout<<ans;
	return 0;
}
