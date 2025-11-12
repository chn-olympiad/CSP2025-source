#include<bits/stdc++.h>
using namespace std;

const int MOD=998244353;
int n,a[5005];
int ans=0;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3){
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2){
			cout<<1;
			return 0;
		}
	}
	for(int i=1;i<=(1<<n)-1;i++){
		int s=1;
		int b[5005],num=1;
		for(int j=1;j<=n;j++){
			if((i&s)!=0){
				b[num]=a[n-j+1];
				num++;
			}
			s<<=1;
		}
		int h=0,mx=0;
		for(int d=1;d<num;d++){
			h+=b[d]; 
			mx=max(mx,b[d]);
		}
		if(h>2*mx){
			ans++;
			ans%=MOD;
		}
	}
	cout<<ans;
	return 0;
}
