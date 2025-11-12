//club.cpp
#include<bits/stdc++.h>
using namespace std;
int t,n,m,x,xx,y,yy,z,zz,a,b,c,ans,ls[1000100][5];
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(false);
	
	cin>>t;
	while(t--){
		cin>>n;
		m=n/2;
		ans=0;
		for(int i=1;i<=n;i++) cin>>ls[i][1]>>ls[i][2]>>ls[i][3];
		if(n==2){
			a=max(ls[1][1]+ls[2][2],ls[1][1]+ls[2][3]);
			b=max(ls[1][2]+ls[2][1],ls[1][2]+ls[2][3]);
			c=max(ls[1][3]+ls[2][1],ls[1][3]+ls[2][2]);
			cout<<max(a,max(b,c));
			continue;
		}
		xx=yy=zz=0;
		for(int i=1;i<=m;i++){
	    	x=y=z=0;
			for(int j=1;j<=n;j++){
				x=max(ls[j][1],x);
				y=max(ls[j][2],y);
				z=max(ls[j][3],z);
			}
			//cout<<x<<' '<<y<<' '<<z<<'\n';
			if(n%3==0&&i==m) ans+=(x+y+z);
			else if(n%3==1&&i==m) ans+=max(x,max(y,z));
			else if(n%3==2&&i==m) ans+=(x+y+z-min(x,min(y,z)));
	    	else ans+=(x+y+z);
	    	//cout<<ans<<'\n';
			for(int j=1;j<=n;j++){
				if(x==ls[j][1]&&xx==0){
					ls[j][1]=ls[j][2]=ls[j][3]=-100;
					xx=1;
				}
				if(y==ls[j][2]&&yy==0){
					ls[j][1]=ls[j][2]=ls[j][3]=-100;
					yy=1;
				}
				if(z==ls[j][3]&&zz==0){
					ls[j][1]=ls[j][2]=ls[j][3]=-100;
					zz=1;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}