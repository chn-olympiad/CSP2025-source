#include<bits/stdc++.h> 
using namespace std;
int n,a[100005][4],t,vs[100005],as,x,y,z,s[5],vis[100005],d,cnt;
struct aa{
	int a[4];
	int w;
} e[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int ii=1;ii<=t;ii++){
		cin>>n;
		as=d=s[1]=s[2]=s[3]=cnt=0;
		for (int i=1;i<=n;i++){
			vs[i]=vis[i]=0;
			scanf("%d%d%d",&e[i].a[1],&e[i].a[2],&e[i].a[3]);
			x=e[i].a[1];
			y=e[i].a[2];
			z=e[i].a[3];
			if (e[i].a[1]>max(e[i].a[2],e[i].a[3])){
				as+=e[i].a[1];
				s[1]++;
				vis[i]=1;
			}
			else if(y>z){
				as+=y;
				s[2]++;
				vis[i]=2;
			}
			else{
				as+=z;
				s[3]++;
				vis[i]=3;
			}
		}
		if (s[1]>n/2){
			d=s[1]-(n/2);
			for (int i=1;i<=n;i++){
				x=e[i].a[1];
				y=e[i].a[2];
				z=e[i].a[3];
				if (vis[i]==1){
					cnt++;
					if (y>z){
						vs[cnt]=x-y;
					}
					else{
						vs[cnt]=x-z;
					}
				}
			}
		}
		else if (s[2]>n/2){
			d=s[2]-(n/2);
			for (int i=1;i<=n;i++){
				x=e[i].a[1];
				y=e[i].a[2];
				z=e[i].a[3];
				if (vis[i]==2){
					cnt++;
					if (x>z){
						vs[cnt]=y-x;
					}
					else{
						vs[cnt]=y-z;
					}
				}
			}
		}
		else if (s[3]>n/2){
			d=s[3]-(n/2);
			for (int i=1;i<=n;i++){
				x=e[i].a[1];
				y=e[i].a[2];
				z=e[i].a[3];
				if (vis[i]==3){
					cnt++;
					if (y>x){
						vs[cnt]=z-y;
					}
					else{
						vs[cnt]=z-x;
					}
				}
			}
		}
		if (cnt>1) sort(vs+1,vs+cnt+1);
		for (int i=1;i<=d;i++){
			as-=vs[i];
		}
		cout<<as<<endl;
	}
	return 0;
}
