#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5*1e5+10;
ll a[N],b[N],k,n,ans=0;
pair<int,int>ls[N];
int pd(int st,int ed){
	if(ans==0) return 1;
	for(int i=1;i<=ans;i++){
		if(!(st<ls[i].first&&ed<ls[i].first||st>ls[i].second&&ed>ls[i].second)) return 0;
	}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		b[i]=(b[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j+i-1<=n;j++){
			if(pd(j,j+i-1)&&(b[j-1]^b[j+i-1])==k){
				ls[++ans]={j,j+i-1};
			}
		}
	}
	cout<<ans;
	return 0;
}
