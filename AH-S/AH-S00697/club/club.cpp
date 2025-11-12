#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
const int maxn=100010;
typedef long long ll;
int t,n,hn,cnt[5],tot;
ll ans;
struct node{
	ll a[5];
	ll t,id;
}p[maxn];
ll b[maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;ans=tot=0;memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			cin>>p[i].a[1]>>p[i].a[2]>>p[i].a[3];
			ll mx=max(max(p[i].a[1],p[i].a[2]),p[i].a[3]);
			for(int k=1;k<=3;k++){
				if(mx==p[i].a[k]){
					ans+=mx;
					cnt[k]++;p[i].id=k;
					ll se=0;
					for(int q=1;q<=3;q++)
						if(q!=k)
							se=max(se,p[i].a[q]);
					p[i].t=mx-se;
					break;
				}
			}
		}
		//cout<<ans<<'\n';
		int ok=0;
		for(int k=1;k<=3;k++)
			if(cnt[k]>n/2)
				ok=k;
		if(ok){
			hn=cnt[ok]-n/2;
			for(int i=1;i<=n;i++)
				if(p[i].id==ok)
					b[++tot]=p[i].t;
			sort(b+1,b+tot+1);
			for(int i=1;i<=tot;i++){
				ans-=b[i];
				hn--;
				if(!hn)
					break;
			}
		}
		cout<<ans<<'\n';
	}	
	return 0;
}
