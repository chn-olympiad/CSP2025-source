#include<bits/stdc++.h>
using namespace std;
int t,n,v[4],ans,a[200001][4],b[200001];
long long bj1,bj2;
int f[101][101][101];
int read(){
	int s=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		s=(s<<1)+(s<<3)+c-'0';
		c=getchar();
	}
	return s*f;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		memset(f,0,sizeof(f));
		bj1=bj2=0;
		for(int i=1;i<=n;i++){
			a[i][1]=read();
			a[i][2]=read();
			a[i][3]=read();
			bj1+=a[i][2]+a[i][3];
			bj2+=a[i][3];
			b[i]=a[i][1];
		}
		if(bj1==0){
			sort(b+1,b+1+n);
			int ans=0;
			for(int i=1;i<=n/2;i++)
			ans+=b[n-i+1];
			cout<<ans<<endl;
		}else 
		if(bj2==0){
			for(int i=1;i<=n;i++)
				for(int x=n/2;x>=0;x--)
					for(int y=n/2;y>=0;y--)
							f[x][y][0]=max(f[x][y][0],max(x==0?-9999999:f[x-1][y][0]+a[i][1],y==0?-9999999:f[x][y-1][0]+a[i][2]));
			cout<<f[n/2][n/2][0]<<endl;
		}else{
			for(int i=1;i<=n;i++)
				for(int x=n/2;x>=0;x--)
					for(int y=n/2;y>=0;y--)
						for(int z=n/2;z>=0;z--)
							f[x][y][z]=max(max(f[x][y][z],z==0?-9999999:f[x][y][z-1]+a[i][3]),max(x==0?-9999999:f[x-1][y][z]+a[i][1],y==0?-9999999:f[x][y-1][z]+a[i][2]));
			cout<<f[n/2][n/2][n/2]<<endl;
		}
		
	}
	return 0;
}