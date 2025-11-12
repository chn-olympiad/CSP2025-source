#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[1000010],b[10010],c[10010],d[10010],ans=0;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int d=k,g=0;
	while(d>0){
		if(d%2==1) {b[g]++;d--;}
		d/=2;
		g++;
	}
	for(int i=1;i<=n;i++){
		int x=a[i],y=0;
		while(x>0){
		if(x%2==1) {
			if(c[y]==1){
				c[y]=0;
				x--;
			}
			else{
				c[y]=1;
				x--;
			}
		}
		x/=2;
		y++;
		}
		if(y>g){
			for(int j=0;j<=y;j++){
				c[y]=0;
			}
			continue;
		}
		int z=0;
		for(int j=0;j<g;j++){
			if(b[j]!=c[j]) z=1;
		}
		if(z==0){
			ans++;
			for(int j=0;j<=g;j++){
				c[j]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
