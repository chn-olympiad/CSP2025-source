#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,xa,xb,xc,ix,ax,mx;
};
int t;
bool cmp(node x,node y){
	if(x.ix==y.ix){
		return x.mx>y.mx;
	}
	return x.ix<y.ix;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,x=0,y=0,z=0,k=0;
		node a[10001];
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			k+=(a[i].a+a[i].b+a[i].c);
			a[i].xa=a[i].b+a[i].c;
			a[i].xb=a[i].a+a[i].c;
			a[i].xc=a[i].b+a[i].a;
			a[i].ix=min(a[i].xa,min(a[i].xb,a[i].xc));
			a[i].ax=max(a[i].xa,max(a[i].xb,a[i].xc));
			if(a[i].ix==a[i].xa&&a[i].ax==a[i].xb){
				a[i].mx=a[i].xc;
			}
			if(a[i].ix==a[i].xa&&a[i].ax==a[i].xc){
				a[i].mx=a[i].xb;
			}
			else{
				a[i].mx=a[i].xa;
			}
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
	  		if(a[i].xa==a[i].ix){
				if(x!=n/2){
					k-=a[i].ix;
					x++;
				}
				else{
					k-=a[i].mx;
				}
			}
			else if(a[i].xb==a[i].ix){
				if(y!=n/2){
					k-=a[i].ix;
					y++;
				}
				else{
					k-=a[i].mx;
				}
			}
			else if(a[i].xc==a[i].ix){
				if(z!=n/2){
					k-=a[i].ix;
					z++;
				}
				else{
					k-=a[i].mx;
				}
			}
		}
		cout<<k<<endl;
	}
}
