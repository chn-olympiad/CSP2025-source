#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e4+5;
ll t,n,a[N],b[N],c[N],a1[N],b1[N],c1[N],m,j,k,sa,sum[N],pre[N];
vector<ll> ans;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>t;
while(t--){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	if(n==2){
	    a1[1]=a[1]+b[2];
	    a1[2]=a[1]+c[2];
	    m=max(a1[1],a1[2]);
	    b1[1]=b[1]+a[2];
	    b1[2]=b[1]+c[2];
	    j=max(b1[1],b1[2]);
	    c1[1]=c[1]+a[2];
	    c1[2]=c[1]+b[2];
	    k=max(c1[1],c1[2]);
	    sa=max(m,j);
	    sa=max(sa,k);
	    ans.push_back(sa);
	}
	if(n==4){
		ll lz=0;
		lz=max(a[1],b[1]);
		lz=max(lz,c[1]);
		for(int i=1;i<=3;i++){
			sum[i]=max(a[i+1],b[i+1]);
			sum[i]=max(sum[i],c[i+1]);
		}
		for(int i=1;i<=3;i++){
			pre[i]=pre[i-1]+sum[i];
		}
		ans.push_back(pre[3]+lz);
	}
}
for(auto o:ans)
{
	cout<<o<<endl;
}
}
