#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
struct node{
	int s,k;
}tx[N],ty[N],tz[N];
int t;
int n,x,y,z;
int a[N][5],c[N];
long long ans=0;

bool cmp1(node x,node y){
	if(x.s<y.s||(x.s==y.s&&x.k<y.k)) return true;
	else return false;
	
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0,x=0,y=0,z=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			tx[i].s=min(a[i][1]-a[i][2],a[i][1]-a[i][3]),tx[i].k=i;
			ty[i].s=min(a[i][2]-a[i][1],a[i][2]-a[i][3]),ty[i].k=i;
			tz[i].s=min(a[i][3]-a[i][1],a[i][3]-a[i][2]),tz[i].k=i;
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				ans+=a[i][1];
				c[i]=1;
				x++;
			}else if(a[i][2]>=a[i][3]){
				ans+=a[i][2];
				c[i]=2;
				y++;
			}else{
				ans+=a[i][3];
				c[i]=3;
				z++;
			}
		}
		if(x>n/2){
			sort(tx+1,tx+1+n,cmp1);
			for(int i=1;i<=n;i++){
				if(c[tx[i].k]==1){
					ans-=tx[i].s;
					x--;
				}
				if(x==n/2) break;
			}
		}else if(y>n/2){
			sort(ty+1,ty+1+n,cmp1);
			for(int i=1;i<=n;i++){
				if(c[ty[i].k]==2){
					ans-=ty[i].s;
					y--;
				}
				if(y==n/2) break;
			}
		}else if(z>n/2){
			sort(tz+1,tz+1+n,cmp1);
			for(int i=1;i<=n;i++){
				if(c[tz[i].k]==3){
					ans-=tz[i].s;
					z--;
				}
				if(z==n/2) break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
