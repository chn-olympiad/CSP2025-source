#include<bits/stdc++.h>
using namespace std;
int a[100005][5],b[100005];
int cmp(int x,int y){
	return x>y;
}

struct node{
	int xh,f;
}c[100005],d[100005];
int cmpp(node x,node y){
	return x.f>y.f;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t; 
	cin>>t;
	while(t--){	
		int n;
		cin>>n;
		bool p=1,q=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j==1){
					c[i].f=a[i][j];
					c[i].xh=i;
				}
				if(j==2){
					d[i].f=a[i][j];
					d[i].xh=i;
				}
				if(j==2&&a[i][j]!=0) p=0;
				if(j==3&&a[i][j]!=0) p=0,q=0;
			}
		}
		if(p){
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];	
			}
			sort(b+1,b+1+n,cmp);
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=b[i];
			}
			cout<<sum;
			return 0;
		}
		if(q){
			sort(c+1,c+1+n,cmpp);
			sort(d+1,d+1+n,cmpp);
			int ct=n/2+1,dt=n/2+1;
			for(int i=1;i<=n/2;i++){
				for(int j=n/2+1;j<=n;j++){
					if(c[i].xh==d[j].xh){
						d[j].f=0;
					}
					
				}
			}
			for(int i=1;i<=n/2;i++){
				for(int j=n/2+1;j<=n;j++){
					if(c[j].xh==d[i].xh){
						c[j].f=0;
					}
				}
			}
			for(int i=1;i<=n/2;i++){
				for(int j=1;j<=n/2;j++){
					if(c[i].xh==d[j].xh){
						while(c[ct].f==0) ct++;
						while(d[dt].f==0) dt++;
						if(c[ct].f+d[j].f>=d[dt].f+c[i].f){
							c[i].f=0;
							for(int k=dt;k<=n;k++){
								if(c[ct].xh==d[k].xh) d[k].f=0;
							}
							ct++;
							
						}
						else{
							d[j].f=0;
							for(int k=ct;k<=n;k++){
								if(d[dt].xh==c[k].xh) c[k].f=0;
							}
							dt++;
						}
					}
				}
			}
			int sum=0;
			for(int i=1;i<=n;i++){
				sum=sum+c[i].f+d[i].f;
			}						
			cout<<sum;
			return 0;
		}
		else{
			int sum=0;
			for(int i=1;i<=n;i++){
				int xxx=0;
				for(int j=1;j<=3;j++){
					xxx=max(xxx,a[i][j]);
				}
				sum+=xxx;
			}
			cout<<sum;
		}
	}

	return 0;
}
