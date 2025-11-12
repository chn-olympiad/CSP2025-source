#include<bits/stdc++.h>
using namespace std;
#define int LL
typedef long long LL;
int t,n,ant,tot1,tot2,tot3;
int a[100010],b[100010],c[100010],dp[100010][3];
int a1[100010],b1[100010],c1[100010],d[100010];//a1,a2,a3存最大值d存最大和第二大的差值
int mx1,mx2,mx3;
bool cmp(int x,int y){
	if(x==0){
		return false;
	}
	if(y==0){
		return true;
	}
	return x<y;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ant=0,mx1=0,mx2=0,mx3=0;
		memset(a1,0,sizeof(a1));
		memset(b1,0,sizeof(b1));
		memset(c1,0,sizeof(c1));
		memset(d,0,sizeof(d));
		for(int i=1;i<=n;i++){		
			cin>>a[i]>>b[i]>>c[i];
			int mx=max(max(a[i],b[i]),c[i]);
			ant+=mx;
			if(mx==0){
				continue;
			}
			if(a[i]!=b[i]&&b[i]!=c[i]){
				if(a[i]==mx){
					a1[++tot1]=a[i];
					mx1++;
				}
				if(b[i]==mx){
					b1[++tot2]=b[i];
					mx2++;
				}
				if(c[i]==mx){
					c1[++tot3]=c[i];
					mx3++;
				}
			}else if(a[i]==b[i]&&b[i]==c[i]){
				if(mx==a[i]){
					++mx1;
					++mx2;
					++mx3;
					a1[++tot1]=a[i];
				}				
			}else{
				if(a[i]==b[i]){
					if(mx==a[i]){
						++mx1;
						++mx2;
						a1[++tot1]=a[i];
					}
					if(mx==c[i]){
						++mx3;
						c1[++tot3]=c[i];
					}
				}else if(b[i]==c[i]){
					if(mx==b[i]){
						++mx2;
						++mx3;
						b1[++tot2]=b[i];
					}
					if(mx==a[i]){
						++mx1;
						a1[++tot1]=a[i];
					}
				}else if(a[i]==c[i]){
					if(mx==b[i]){
						++mx2;
						b1[++tot2]=b[i];
					}
					if(mx==a[i]){
						++mx1;
						++mx3;
						a1[++tot1]=a[i];
					}
				}
			}
		}
		if((mx1<=n/2)&&(mx2<=n/2)&&(mx3<=n/2)){
			cout<<ant<<"\n";
		}else{
			
			if((mx1+mx2+mx3)==n){
				int x;
				if(mx1>n/2){
					x=mx1-n/2;
					for(int i=1;i<=n;i++){
						if(a[i]>max(b[i],c[i])){
							d[i]=a[i]-max(b[i],c[i]);
						}
					}
				}else if(mx2>n/2){
					x=mx2-n/2;
					for(int i=1;i<=n;i++){
						if(b[i]>max(a[i],c[i])){
							d[i]=b[i]-max(a[i],c[i]);
						}
					}
				}else if(mx3>n/2){
					x=mx3-n/2;
					for(int i=1;i<=n;i++){
						if(c[i]>max(a[i],b[i])){
							d[i]=c[i]-max(a[i],b[i]);
						}
					}
				}
				sort(d+1,d+1+n,cmp);
				for(int i=1;i<=x;i++){
					ant-=d[i];
				}
				cout<<ant<<"\n";
			}else{
				if((max(mx1,max(mx2,mx3))-n/2)<=(mx1+mx2+mx3-n)){
					cout<<ant<<"\n";
				}else{
					int x;
					if(mx1>n/2){
						x=mx1-n/2;
						for(int i=1;i<=n;i++){
							if(a[i]>max(b[i],c[i])){
								d[i]=a[i]-max(b[i],c[i]);
							}
						}
					}else if(mx2>n/2){
						x=mx2-n/2;
						for(int i=1;i<=n;i++){
							if(b[i]>max(a[i],c[i])){
								d[i]=b[i]-max(a[i],c[i]);
							}
						}
					}else if(mx3>n/2){
						x=mx3-n/2;
						for(int i=1;i<=n;i++){
							if(c[i]>max(a[i],b[i])){
								d[i]=c[i]-max(a[i],b[i]);
							}
						}
					}
					sort(d+1,d+1+n,cmp);
					for(int i=1;i<=x-(mx1+mx2+mx3-n);i++){
						ant-=d[i];
					}
					cout<<ant<<"\n";
				}
			}			
		}		
	}
	return 0;
}