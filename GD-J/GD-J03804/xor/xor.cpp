#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N],idx,b[N],ans;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)b[i]=a[i]+a[i-1];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((b[j]-b[i-1])%2==0)ans++;
		}
	}
	cout<<ans;
	return 0;
}
