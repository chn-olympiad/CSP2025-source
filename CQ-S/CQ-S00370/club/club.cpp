#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int o=1;o<=t;o++){
		int n;
		cin>>n;
		int a[10005],b[10005],c[10005];
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];	
		}
		int y=0;
		int aa=0,bb=0,cc=0;
		for(int i=1;i<=n*2;i++){
			int p1=0,p2=0,p3=0;
			int ax,bx,cx;
			if(aa<n/2){
				for(int i=1;i<=n;i++){
					if(p1<a[i]){
						p1=a[i];
						ax=i;
					}
				}
			}
			if(bb<n/2){
				for(int i=1;i<=n;i++){
					if(p2<b[i]){
						p2=b[i];
						bx=i;
					}
				}
			}
			if(cc<n/2){
				for(int i=1;i<=n;i++){
					if(p3<c[i]){
						p3=c[i];
						cx=i;
					}
				}
			}
			int p=max(p1,max(p2,p3));
			if(ax==bx==cx){
				if(p==p1){
					a[ax]=0;
				}
				if(p==p2){
					b[ax]=0;
				}
				if(p==p3){
					c[ax]=0;
				}
			}
			else if(p==p1){
				y+=p;
				aa++;
				a[ax]=0;
				b[ax]=0;
				c[ax]=0;
			}
			else if(p==p2){
				y+=p;
				bb++;
				a[bx]=0;
				b[bx]=0;
				c[bx]=0;
			}
			else if(p==p3){
				y+=p;
				cc++;
				a[cx]=0;
				b[cx]=0;
				c[cx]=0;
			}
		}
		cout<<y;
			
	}
	
	
	return 0;
} 
