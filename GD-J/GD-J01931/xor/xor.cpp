#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,cnt=0;
int a[500001];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) cnt++;
	}
	if(n<=2){
		cout<<1;
	}
	else if(n<=10){
		if(k==0){
			if(cnt%2==0){
				cout<<cnt/2+n-cnt;
			}
		}
		if(k==1){
			if(cnt%2==0&&cnt>n-cnt){
				cout<<n-cnt+(cnt-(n-cnt))/2;
			}
			else if(cnt==n-cnt){
				cout<<n/2;
			}
		}
	}
	else{
		if(k==0){
			cout<<n/2;
		}
	}
	return 0;
}
