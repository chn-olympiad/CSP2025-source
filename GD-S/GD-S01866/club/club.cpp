#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int x,y,z;
}a[100005],b[100005];
bool cmp1(node l,node r){
	return l.x>r.x;
}
bool cmp2(node l,node r){
	return abs(l.y-l.x)>abs(r.y-r.x);
}
bool cmp3(node a,node b){
	int mxa=max({a.x,a.y,a.z}),mna=min({a.x,a.y,a.z}),mda;
	if(mxa==a.x){
		if(mna==a.y)mda=a.z;
		else mda=a.y;
	}
	if(mxa==a.y){
		if(mna==a.x)mda=a.z;
		else mda=a.x;
	}
	if(mxa==a.z){
		if(mna==a.x)mda=a.y;
		else mda=a.x;
	}
	int mxb=max({b.x,b.y,b.z}),mnb=min({b.x,b.y,b.z}),mdb;
	if(mxb==b.x){
		if(mnb==b.y)mda=b.z;
		else mdb=b.y;
	}
	if(mxb==b.y){
		if(mnb==b.x)mdb=b.z;
		else mdb=b.x;
	}
	if(mxb==b.z){
		if(mnb==b.x)mda=b.y;
		else mdb=b.x;
	}
	return mxa-mna+mxa-mda>mxb-mnb+mxb-mdb;
}
bool cmp4(node l,node r){
	return l.z>r.z;
}
bool cmp5(node l,node r){
	return l.y>r.y;
}
bool cmp6(node l,node r){
	return abs(l.z-l.x)>abs(r.z-r.x);
}
bool cmp7(node l,node r){
	return abs(l.z-l.y)>abs(r.z-r.y);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,ans=0;
		cin>>n;
		int f=0,g=0,h=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].x!=0)h=1;
			if(a[i].y!=0)f=1;
			if(a[i].z!=0)g=1;
		}
		if(!h&&!f){
			sort(a+1,a+1+n,cmp4);
			for(int i=1;i<=n/2;i++)ans+=a[i].z;
			cout<<ans<<endl;
			continue;
		}
		if(!h&&!g){
			sort(a+1,a+1+n,cmp5);
			for(int i=1;i<=n/2;i++)ans+=a[i].y;
			cout<<ans<<endl;
			continue;
		}
		if(!g&&!f){
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n/2;i++)ans+=a[i].x;
			cout<<ans<<endl;
			continue;
		}
		if(h&&f&&!g){
			sort(a+1,a+1+n,cmp2);
			int x=n/2,y=n/2;
			for(int i=1;i<=n;i++){
				if(a[i].x>a[i].y){
					if(x>0)x--,ans+=a[i].x;
					else if(y>0)y--,ans+=a[i].y;
					else break; 
				}
				if(a[i].x<a[i].y){
					if(y>0)y--,ans+=a[i].y;
					else if(x>0)x--,ans+=a[i].x;
					else break;
				}
				if(a[i].x==a[i].y){
					if(x>y)x--,ans+=a[i].x;
					if(x<y)y--,ans+=a[i].y;
				}
			}
			cout<<ans<<endl;
			continue;
		}
		if(h&&!f&&g){
			sort(a+1,a+1+n,cmp6);
			int x=n/2,z=n/2;
			for(int i=1;i<=n;i++){
				if(a[i].x>a[i].z){
					if(x>0)x--,ans+=a[i].x;
					else if(z>0)z--,ans+=a[i].z;
					else break; 
				}
				if(a[i].x<a[i].z){
					if(z>0)z--,ans+=a[i].z;
					else if(x>0)x--,ans+=a[i].x;
					else break;
				}
				if(a[i].x==a[i].z){
					if(x>z)x--,ans+=a[i].x;
					if(x<z)z--,ans+=a[i].z;
				}
			}
			cout<<ans<<endl;
			continue;
		}
		if(!h&&f&&g){
			sort(a+1,a+1+n,cmp7);
			int y=n/2,z=n/2;
			for(int i=1;i<=n;i++){
				if(a[i].y>a[i].z){
					if(y>0)y--,ans+=a[i].y;
					else if(z>0)z--,ans+=a[i].z;
					else break; 
				}
				if(a[i].y<a[i].z){
					if(z>0)z--,ans+=a[i].z;
					else if(y>0)y--,ans+=a[i].y;
					else break;
				}
				if(a[i].y==a[i].z){
					if(y>z)y--,ans+=a[i].y;
					if(y<z)z--,ans+=a[i].z;
				}
			}
			cout<<ans<<endl;
			continue;
		}
		int x=n/2,y=n/2,z=n/2,l=0;
		sort(a+1,a+1+n,cmp3);
		for(int i=1;i<=n;i++){
			if(a[i].x>a[i].y&&a[i].x>a[i].z){
				if(x>0)x--,ans+=a[i].x;
				else{
					if(a[i].y>a[i].z){
						if(y>0)y--,ans+=a[i].y;
						else z--,ans+=a[i].z;
					}
					else if(a[i].y<a[i].z){
						if(z>0)z--,ans+=a[i].z;
						else y--,ans+=a[i].y;
					}
					else{
						if(y>z)y--,ans+=a[i].y;
						else if(y<z)z--,ans+=a[i].z;
						else b[++l]=a[i];
					}
				}
			}
			if(a[i].y>a[i].x&&a[i].y>a[i].z){
				if(y>0)y--,ans+=a[i].y;
				else{
					if(a[i].x>a[i].z){
						if(x>0)x--,ans+=a[i].x;
						else z--,ans+=a[i].z;
					}
					else if(a[i].x<a[i].z){
						if(z>0)z--,ans+=a[i].z;
						else x--,ans+=a[i].x;
					}
					else{
						if(x>z)x--,ans+=a[i].x;
						else if(x<z)z--,ans+=a[i].z;
						else b[++l]=a[i];
					}
				}
			}
			if(a[i].z>a[i].y&&a[i].z>a[i].x){
				if(z>0)z--,ans+=a[i].z;
				else{
					if(a[i].x>a[i].y){
						if(x>0)x--,ans+=a[i].x;
						else y--,ans+=a[i].y;
					}
					else if(a[i].x<a[i].y){
						if(y>0)y--,ans+=a[i].y;
						else x--,ans+=a[i].x;
					}
					else{
						if(x>y)x--,ans+=a[i].x;
						else if(x<y)y--,ans+=a[i].y;
						else b[++l]=a[i];
					}
				}
			}
		}
		if(l>0){
			sort(b+1,b+1+l,cmp3);
			for(int i=1;i<=l;i++){
				if(a[i].x>a[i].y&&a[i].x>a[i].z){
					if(x>0)x--,ans+=a[i].x;
					else{
						if(a[i].y>a[i].z){
							if(y>0)y--,ans+=a[i].y;
							else z--,ans+=a[i].z;
						}
						else if(a[i].y<a[i].z){
							if(z>0)z--,ans+=a[i].z;
							else y--,ans+=a[i].y;
						}
						else{
							if(y>z)y--,ans+=a[i].y;
							else if(y<z)z--,ans+=a[i].z;
							else b[++l]=a[i];
						}
					}
				}
				if(a[i].y>a[i].x&&a[i].y>a[i].z){
					if(y>0)y--,ans+=a[i].y;
					else{
						if(a[i].x>a[i].z){
							if(x>0)x--,ans+=a[i].x;
							else z--,ans+=a[i].z;
						}
						else if(a[i].x<a[i].z){
							if(z>0)z--,ans+=a[i].z;
							else x--,ans+=a[i].x;
						}
						else{
							if(x>z)x--,ans+=a[i].x;
							else if(x<z)z--,ans+=a[i].z;
							else b[++l]=a[i];
						}
					}
				}
				if(a[i].z>a[i].y&&a[i].z>a[i].x){
					if(z>0)z--,ans+=a[i].z;
					else{
						if(a[i].x>a[i].y){
							if(x>0)x--,ans+=a[i].x;
							else y--,ans+=a[i].y;
						}
						else if(a[i].x<a[i].y){
							if(y>0)y--,ans+=a[i].y;
							else x--,ans+=a[i].x;
						}
						else{
							if(x>y)x--,ans+=a[i].x;
							else if(x<y)y--,ans+=a[i].y;
							else b[++l]=a[i];
						}
					}
				}
			}
		}
		cout<<ans<<endl; 
	}
	return 0;
}
