#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
}a[100005],x[100005],y[100005],z[100005];
int t,n,xl,yl,zl,mx,mx2,p,s;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		s=xl=yl=zl=0;
		for(int i=1;i<=n;i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			mx=0;
			mx=max(a[i].x,max(a[i].y,a[i].z));
			if(a[i].x==mx){
				if(xl==n/2){
					mx2=0;
					for(int j=1;j<=xl;j++){
						if(mx2<max(x[j].y,x[j].z)){
							mx2=max(x[j].y,x[j].z);
							if(mx2==x[j].y||mx2==x[j].z){
								p=j;
							}
						}
					}
					if(mx+mx2-x[p].x>max(a[i].y,a[i].z)){
						if(x[p].y>x[p].z){
							y[++yl]=x[p];
						}
						else{
							z[++zl]=x[p];
						}
						s=s+mx+mx2-x[p].x;
						x[p]=a[i];
					}
					else{
						if(a[i].y>a[i].z){
							y[++yl]=a[i];
						}
						else{
							z[++zl]=a[i];
						}
						s=s+max(a[i].y,a[i].z);
					}
				}
				else{
					x[++xl]=a[i];
					s=s+a[i].x;
				}
			}
			else if(a[i].y==mx){
				if(yl==n/2){
					mx2=0;
					for(int j=1;j<=yl;j++){
						if(mx2<max(y[j].x,y[j].z)){
							mx2=max(y[j].x,y[j].z);
							if(mx2==y[j].x||mx2==y[j].z){
								p=j;
							}
						}
					}
					if(mx+mx2-y[p].y>max(a[i].x,a[i].z)){
						if(y[p].x>y[p].z){
							x[++xl]=y[p];
						}
						else{
							z[++zl]=x[p];
						}
						s=s+mx+mx2-y[p].y;
						y[p]=a[i];
					}
					else{
						if(a[i].x>a[i].z){
							x[++xl]=a[i];
						}
						else{
							z[++zl]=a[i];
						}
						s=s+max(a[i].x,a[i].z);
					}
				}
				else{
					y[++yl]=a[i];
					s=s+a[i].y;
				}
			}
			else if(a[i].z==mx){
				if(zl==n/2){
					mx2=0;
					for(int j=1;j<=yl;j++){
						if(mx2<max(z[j].x,z[j].y)){
							mx2=max(z[j].x,z[j].y);
							if(mx2==z[j].x||mx2==z[j].y){
								p=j;
							}
						}
					}
					if(mx+mx2-z[p].z>max(a[i].x,a[i].y)){
						if(z[p].x>z[p].y){
							x[++xl]=z[p];
						}
						else{
							y[++yl]=z[p];
						}
						s=s+mx+mx2-z[p].z;
						y[p]=a[i];
					}
					else{
						if(a[i].x>a[i].y){
							x[++xl]=a[i];
						}
						else{
							y[++yl]=a[i];
						}
						s=s+max(a[i].x,a[i].y);
					}
				}
				else{
					z[++zl]=a[i];
					s=s+a[i].z;
				}
			}
		}
		cout << s << '\n';
	}
	return 0;
}
