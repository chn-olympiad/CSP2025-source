#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,m,cnt;
ll a[2525];
ll b[2525][2525];
ll sum=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				b[j][i]=sum;
				sum++;
			}	
		}else{
			for(int j=n;j>0;j--){
				b[j][i]=sum;
				sum++;
			}
		} 
	}
	ll len=n*m;
	for(int i=1;i<=len;i++){
		cin>>a[i];	
	}
	ll k=a[1];
	sort(a+1,a+1+len,greater<ll>());
	for(int i=1;i<=len;i++){
		if(a[i]==k){
			cnt=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(cnt==b[i][j]){
				cout<<j<<' '<<i;
				break;
			}		
		}
	}
	return 0;
}
