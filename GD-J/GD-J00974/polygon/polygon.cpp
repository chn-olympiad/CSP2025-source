#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=998244353;
ll n,sum,mx=-9999,cnt;
ll a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		mx=max(mx,a[i]);
	}
	if(sum>mx*2){
		cnt++;
	}
	cout<<cnt%M;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

