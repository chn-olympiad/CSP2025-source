#include <bits/stdc++.h>
using namespace std;
int g=1,a[100005],b[100005],c[100005],x,y,z,m1[100005],m2[100005],m3[100005];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,nn,an,zs;
	scanf("%d",&t);
	while(t--){
		x=0;y=0;z=0;
		an=0;
		g=1;
		scanf("%d",&n);
		nn=n/2;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			if(a[i]>=max(b[i],c[i])){
			an+=a[i];
				x++;
				m1[i]=a[i]-max(b[i],c[i]);
				m2[i]=20005;
				m3[i]=20005;
			}else if(b[i]>=max(a[i],c[i])){
				an+=b[i];
				y++;
				m2[i]=b[i]-max(a[i],c[i]);
				m1[i]=20005;
				m3[i]=20005;
			}else if(c[i]>=max(b[i],a[i])){
				z++;
				an+=c[i];
				m3[i]=c[i]-max(b[i],a[i]);
				m2[i]=20005;
				m1[i]=20005;
			}
		}
		if(x>nn){
			sort(m1+1,m1+n+1,cmp);
			for(int i=1;i<=x-nn;i++){
				an-=m1[i];
			}
		}
		if(y>nn){
			sort(m2+1,m2+n+1,cmp);
			for(int i=1;i<=y-nn;i++){
				an-=m2[i];
			}
		}if(z>nn){
			sort(m3+1,m3+n+1,cmp);
			for(int i=1;i<=z-nn;i++){
				an-=m3[i];
			}
		}
		printf("%d\n",an);
	}
		return 0;
}
