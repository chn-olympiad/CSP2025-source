#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
struct node{
	int x,y,z;
}q[100005];
struct node1{
	int x1,y1,z1;
}a[100005];
struct node2{
	int x2,y2,z2;
}b[100005];
struct node3{
	int x3,y3,z3;
}c[100005];
int cmp1(node1 a1,node1 b1){
	return a1.x1>b1.x1;
}
int cmp2(node2 a2,node2 b2){
	return a2.x2>b2.x2;
}
int cmp3(node3 a3,node3 b3){
	return a3.x3>b3.x3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(q,0,sizeof(q));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		cin>>n;
		int e=0,e1=0,e2=0,ans=0;
		for(int i=1;i<=n;i++){
			cin>>q[i].x>>q[i].y>>q[i].z;
			int w=max(q[i].x,q[i].y);
			w=max(w,q[i].z);
			if(q[i].x==w){
				e++,a[e].x1=q[i].x,a[e].y1=i,a[e].z1=1;
			} 
			else{
				if(q[i].y==w){
					e1++,b[e1].x2=q[i].y,b[e1].y2=i,b[e1].z2=2;
				}
				else{
					if(q[i].z==w) e2++,c[e2].x3=q[i].z,c[e2].y3=i,c[e2].z3=3;
				}
			}
		}
		sort(a+1,a+e+1,cmp1);
		sort(b+1,b+e1+1,cmp2);
		sort(c+1,c+e2+1,cmp3);
		for(int i=1;i<=n/2;i++){
			ans+=a[i].x1+b[i].x2+c[i].x3;
		}
		if(e>n/2){
			for(int i=1;i<=e-n/2;i++){
				if(a[n/2+i].z1==1){
					if(q[a[n/2+i].y1].y>=q[a[n/2+i].y1].z){
						if(e1<n/2)
						   ans+=q[a[n/2+i].y1].y;
						else{
							if(e2<n/2) ans+=q[a[n/2+i].y1].z;
						}
					}
					else{
						if(e2<n/2)
						   ans+=q[a[n/2+i].y1].z;
						else{
							if(e1<n/2) ans+=q[a[n/2+i].y1].y;
						}
					}
					    
				}
				if(a[n/2+i].z1==2){
					if(q[a[n/2+i].y1].x>=q[a[n/2+i].y1].z){
						if(e<n/2)
						   ans+=q[a[n/2+i].y1].x;
						else{
							if(e2<n/2) ans+=q[a[n/2+i].y1].z;
						}
					}
					else{
						if(e2<n/2)
						   ans+=q[a[n/2+i].y1].z;
						else{
							if(e<n/2) ans+=q[a[n/2+i].y1].x;
						}
					}
					    
				}
				if(a[n/2+i].z1==3){
					if(q[a[n/2+i].y1].y>=q[a[n/2+i].y1].x){
						if(e1<n/2)
						   ans+=q[a[n/2+i].y1].y;
						else{
							if(e<n/2) ans+=q[a[n/2+i].y1].z;
						}
					}
					else{
						if(e<n/2)
						   ans+=q[a[n/2+i].y1].x;
						else{
							if(e1<n/2) ans+=q[a[n/2+i].y1].y;
						}
					}
					    
				}
			}
		}
		if(e1>n/2){
			for(int i=1;i<=e1-n/2;i++){
				if(b[n/2+i].z2==1){
					if(q[b[n/2+i].y2].y>=q[b[n/2+i].y2].z){
						if(e1<n/2)
						   ans+=q[b[n/2+i].y2].y;
						else{
							if(e2<n/2) ans+=q[b[n/2+i].y2].z;
						}
					}
					else{
						if(e2<n/2)
						   ans+=q[b[n/2+i].y2].z;
						else{
							if(e1<n/2) ans+=q[b[n/2+i].y2].y;
						}
					}
					    
				}
				if(b[n/2+i].z2==2){
					if(q[b[n/2+i].y2].x>=q[b[n/2+i].y2].z){
						if(e<n/2)
						   ans+=q[b[n/2+i].y2].x;
						else{
							if(e2<n/2) ans+=q[b[n/2+i].y2].z;
						}
					}
					else{
						if(e2<n/2)
						   ans+=q[b[n/2+i].y2].z;
						else{
							if(e<n/2) ans+=q[b[n/2+i].y2].x;
						}
					}
					    
				}
				if(b[n/2+i].z2==3){
					if(q[b[n/2+i].y2].y>=q[b[n/2+i].y2].x){
						if(e1<n/2)
						   ans+=q[b[n/2+i].y2].y;
						else{
							if(e<n/2) ans+=q[b[n/2+i].y2].z;
						}
					}
					else{
						if(e<n/2)
						   ans+=q[b[n/2+i].y2].x;
						else{
							if(e1<n/2) ans+=q[b[n/2+i].y2].y;
						}
					}
					    
				}
			}
		}
		if(e2>n/2){
			for(int i=1;i<=e2-n/2;i++){
				if(c[n/2+i].z3==1){
					if(q[c[n/2+i].y3].y>=q[c[n/2+i].y3].z){
						if(e1<n/2)
						   ans+=q[c[n/2+i].y3].y;
						else{
							if(e2<n/2) ans+=q[c[n/2+i].y3].z;
						}
					}
					else{
						if(e2<n/2)
						   ans+=q[c[n/2+i].y3].z;
						else{
							if(e1<n/2) ans+=q[c[n/2+i].y3].y;
						}
					}
					    
				}
				if(c[n/2+i].z3==2){
					if(q[c[n/2+i].y3].x>=q[c[n/2+i].y3].z){
						if(e<n/2)
						   ans+=q[c[n/2+i].y3].x;
						else{
							if(e2<n/2) ans+=q[c[n/2+i].y3].z;
						}
					}
					else{
						if(e2<n/2)
						   ans+=q[c[n/2+i].y3].z;
						else{
							if(e<n/2) ans+=q[c[n/2+i].y3].x;
						}
					}
					    
				}
				if(c[n/2+i].z3==3){
					if(q[c[n/2+i].y3].y>=q[c[n/2+i].y3].x){
						if(e1<n/2)
						   ans+=q[c[n/2+i].y3].y;
						else{
							if(e<n/2) ans+=q[c[n/2+i].y3].z;
						}
					}
					else{
						if(e<n/2)
						   ans+=q[c[n/2+i].y3].x;
						else{
							if(e1<n/2) ans+=q[c[n/2+i].y3].y;
						}
					}
					    
				}
			}
		}
		//cout<<a[1].x1<<" "<<b[1].x2<<" "<<c[1].x3;
		cout<<ans<<endl;
	}
	return 0;
}
