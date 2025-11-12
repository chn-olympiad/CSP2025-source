#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+7;
ll a[N][3],b[N];
ll n,m,k,q,ans,cnt,pos,sum,tot,opt,mx=-1e9,l,r,mid,x,y,z;
ll rd(){
	char c=getchar();ll x=0;
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	q=rd();
	while(q--){
		n=rd(),ans=pos=x=y=z=0;
		for(ll i=1;i<=n;i++){
			a[i][0]=rd(),a[i][1]=rd(),a[i][2]=rd(),ans+=max(a[i][0],max(a[i][1],a[i][2]));
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])x++;
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2])y++;
			else if(a[i][2]>=a[i][0]&&a[i][2]>=a[i][1])z++;
		}
		if(x*2<=n&&y*2<=n&&z*2<=n){
			cout<<ans<<"\n";continue;
		}
		for(ll i=1;i<=n;i++){
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]&&x*2>n)b[++pos]=a[i][0]-max(a[i][1],a[i][2]);
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]&&y*2>n)b[++pos]=a[i][1]-max(a[i][2],a[i][0]);
			else if(a[i][2]>=a[i][0]&&a[i][2]>=a[i][1]&&z*2>n)b[++pos]=a[i][2]-max(a[i][1],a[i][0]);
		}
		sort(b+1,b+1+pos);
		for(ll i=1;i<=pos;i++){
			if(x*2>n)x--,ans-=b[i];
			else if(y*2>n)y--,ans-=b[i];
			else if(z*2>n)z--,ans-=b[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
