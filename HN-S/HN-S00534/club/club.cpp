#include<bits/stdc++.h>
using namespace std;
int s[4][1086]={},r=0;
int f(int x,int y,int z,int u){
	if(y==z){
		r=max(r,x);
		return 0;
	}
	if(u==1){
		f(x+s[2][y],y+1,z,2);
		f(x+s[3][y],y+1,z,3);
	}
	else if(u==2){
		f(x+s[1][y],y+1,z,1);
		f(x+s[3][y],y+1,z,3);
	}
	else {
		f(x+s[1][y],y+1,z,1);
		f(x+s[2][y],y+1,z,2);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while (t--){
		long long a,b,c,x1[1086]={},y1[1086]={},z1[1086]={},ans=0;
		cin>>a;
		if(a>1000){
			for (int i=1;i<=a;i++){
			scanf("%d%d%d",&x1[i],&y1[i],&z1[i]);
		}
		for (int j=1;j<=3;j++){
			if(j==1){
				long long p[1086]={},c=0;
				for (int m=1;m<a;m++){
					for (int n=1;n<=a-m;n++){
						if(x1[n]>x1[n+1]){
							swap(x1[n],x1[n+1]);
							swap(y1[n],y1[n+1]);
							swap(z1[n],z1[n+1]);
						}
					}
				}
				for (int m=a;m>a/2;m--){
					c+=x1[m];
					p[m]=1;
				}
				for (int u=1;u<=a/2;u++){
					int maxn=0,l1=0;
					for (int l=1;l<=a;l++){
						if(p[l]==0){
							if(y1[l]>maxn){
								maxn=y1[l];
								l1=l;
							}
							if(z1[l]>maxn){
								maxn=z1[l];
								l1=l;
							}
						}
					}
					if(l1)p[l1]=1;
					c+=maxn;
				}
				ans=max(ans,c);
			}
		else if(j==2){
			long long p[1086]={},c=0;
			for (int m=1;m<a;m++){
				for (int n=1;n<=a-m;n++){
					if(y1[n]>y1[n+1]){
						swap(x1[n],x1[n+1]);
						swap(y1[n],y1[n+1]);
						swap(z1[n],z1[n+1]);
					}
				}
			}
			for (int m=a;m>a/2;m--){
				c+=y1[m];
				p[m]=1;
			}
			for (int u=1;u<=a/2;u++){
				int maxn=0,l1=0;
				for (int l=1;l<=a;l++){
					if(p[l]==0){
						if(x1[l]>maxn){
							maxn=x1[l];
							l1=l;
						}
						if(z1[l]>maxn){
							maxn=z1[l];
							l1=l;
						}
					}
				}
				if(l1)p[l1]=1;
				c+=maxn;
			}
			ans=max(ans,c);
		}
		else if(j==3){
			long long p[1086]={},c=0;
			for (int m=1;m<a;m++){
				for (int n=1;n<=a-m;n++){
					if(z1[n]>z1[n+1]){
						swap(x1[n],x1[n+1]);
						swap(y1[n],y1[n+1]);
						swap(z1[n],z1[n+1]);
					}
				}
			}
			for (int m=a;m>a/2;m--){
				c+=z1[m];
				p[m]=1;
			}
			for (int u=1;u<=a/2;u++){
				int maxn=0,l1=0;
				for (int l=1;l<=a;l++){
					if(p[l]==0){
						if(y1[l]>maxn){
							maxn=y1[l];
							l1=l;
						}
						if(x1[l]>maxn){
							maxn=x1[l];
							l1=l;
						}
					}
				}
				if(l1)p[l1]=1;
				c+=maxn;
			}
			ans=max(ans,c);
			}
		}
		cout<<ans<<"\n";
		}
		else {
			for (int i=1;i<=a;i++){
				scanf("%d%d%d",&s[1][i],&s[2][i],&s[3][i]);
			}
			for (int i=1;i<=3;i++){
				f(s[1][i],1,a,i);
			}
			cout<<r;
		}
	}
	return 0;
}
