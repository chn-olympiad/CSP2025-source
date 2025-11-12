#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x,y,z,h,q;
}a[100005];
long long t,n,b[10],c[10],d[10];
bool cmp(node c,node d){
	if(c.q==d.q) return c.h<d.h;
	return c.q>d.q;
}
bool cmb(node c,node d){
	if(c.q==d.q) return c.h<d.h;
	return c.q<d.q;
}
int main(){
	//freopen("club","r",stdin);
	//freopen("club","w",stdout);
	cin>>t;
	for(int j=0;j<t;j++){
		cin>>n;
		int sx=n/2;
		int sy=n/2;
		int sz=n/2;
		for(int i=0;i<n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].h=i;
			a[i].q=a[i].x+a[i].y+a[i].z;
		}
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++){
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z&&sx>0){
				b[j]+=a[i].x;
				sx--;
			}
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z&&sy>0){
				b[j]+=a[i].y;
				sy--;
			}
			else if(a[i].z>=a[i].y&&a[i].z>=a[i].x&&sz>0){
				b[j]+=a[i].z;
				sz--;
			}
			else if(sx==0){
				if(a[i].y>=a[i].z&&sy>0){
					b[j]+=a[i].y;
					sy--;
				}
				else if(a[i].z>=a[i].y&&sz>0){
					b[j]+=a[i].z;
					sz--;
				}	
			}
			else if(sy==0){
				if(a[i].x>=a[i].z&&sx>0){
					b[j]+=a[i].x;
					sx--;
				}
				else if(a[i].z>=a[i].x&&sz>0){
					b[j]+=a[i].z;
					sz--;
				}	
			}
			else if(sz==0){
				if(a[i].y>=a[i].x&&sy>0){
					b[j]+=a[i].y;
					sy--;
				}
				else if(a[i].x>=a[i].y&&sx>0){
					b[j]+=a[i].x;
					sx--;
				}	
			}
		}
		sx=n/2;
		sy=n/2;
		sz=n/2;
		sort(a,a+n,cmb);
		for(int i=0;i<n;i++){
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z&&sx>0){
				c[j]+=a[i].x;
				sx--;
			}
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z&&sy>0){
				c[j]+=a[i].y;
				sy--;
			}
			else if(a[i].z>=a[i].y&&a[i].z>=a[i].x&&sz>0){
				c[j]+=a[i].z;
				sz--;
			}
			else if(sx==0){
				if(a[i].y>=a[i].z&&sy>0){
					c[j]+=a[i].y;
					sy--;
				}
				else if(a[i].z>=a[i].y&&sz>0){
					c[j]+=a[i].z;
					sz--;
				}	
			}
			else if(sy==0){
				if(a[i].x>=a[i].z&&sx>0){
					c[j]+=a[i].x;
					sx--;
				}
				else if(a[i].z>=a[i].x&&sz>0){
					c[j]+=a[i].z;
					sz--;
				}	
			}
			else if(sz==0){
				if(a[i].y>=a[i].x&&sy>0){
					c[j]+=a[i].y;
					sy--;
				}
				else if(a[i].x>=a[i].y&&sx>0){
					c[j]+=a[i].x;
					sx--;
				}	
			}
		}
	}
	for(int j=0;j<t;j++){
		d[j]=max(b[j],c[j]);
		cout<<d[j]<<endl;
	}
	return 0;
}
