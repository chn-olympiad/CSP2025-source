#include<bits/stdc++.h>
using namespace std;
int n,k,b[505],c[505],m,a[505],x=1,j[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1,ll;i<=n;i++){
		scanf("%d",&ll);
		if(a[ll]==0)x++;
		j[x]=ll;
		a[ll]++;
	}
	sort(j+1,j+x);
	for(int i=n;i>=1;i--) c[i]=c[i+1]+a[i];
	int l=j[1],u=c[1],y=1,h=0,w=0;
	for(int i=1;i<=n;i++){
		l=j[y];
		if(u>l){
			w=w+j[y]-j[y-1];
			y++;
			h=0;
		}
		if(y>=x){
			k+=u-w;
			break;
		}
		if(b[i]==1){
			k+=u-w;
			k=k%998244353;
			w--;
		}
	}
	printf("%d",k);
	return 0;
}
