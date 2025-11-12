#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,ans;
int a[N],lena,b[N],lenb,c[N],lenc;
void solve(){
	ans=0,lena=lenb=lenc=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int m1x=0,m1p=0,m2x=0,m2p=0;
		for(int j=1,x;j<=3;j++){
			cin>>x;
			if(x>=m1x) m2x=m1x,m2p=m1p,m1x=x,m1p=j;
			else if(x>=m2x) m2x=x,m2p=j; 
		}
		//cout<<m1x<<' '<<m1p<<' '<<m2x<<' '<<m2p<<'\n';
		ans+=m1x;
		if(m1p==1) a[++lena]=m1x-m2x;
		if(m1p==2) b[++lenb]=m1x-m2x;
		if(m1p==3) c[++lenc]=m1x-m2x;		
	}
	if(lena>n/2){
		sort(a+1,a+lena+1);
		for(int i=1;i<=lena-n/2;i++) ans-=a[i];
	}
	if(lenb>n/2){
		sort(b+1,b+lenb+1);
		for(int i=1;i<=lenb-n/2;i++) ans-=b[i];
	}
	if(lenc>n/2){
		sort(c+1,c+lenc+1);
		for(int i=1;i<=lenc-n/2;i++) ans-=c[i];
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) solve();
	return 0;
} 
