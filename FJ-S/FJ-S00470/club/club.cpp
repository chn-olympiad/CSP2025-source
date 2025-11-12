#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100001],b[100001],c[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		long long shu=n/2,x=0,y=0,z=0;
		for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
		long long h=0;
		for(int i=1;i<=n;i++){
			if(x==shu)a[i]-=1;
			if(y==shu)b[i]-=1;
			if(z==shu)c[i]-=1;
			int g=max(a[i],max(b[i],c[i]));
			if(g==a[i]&&x<shu)x++;
			if(g==b[i]&&y<shu)y++;
			if(g==c[i]&&z<shu)z++;
			h+=g;
		}cout<<h<<endl;
		}
	return 0;
}