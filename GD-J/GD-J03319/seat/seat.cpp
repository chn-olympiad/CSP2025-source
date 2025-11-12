#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,r=-1,c=-1; //第 r 行，第 c 列 
struct node{
	int x,pos;
}a[1005];
bool cmp(node a,node b){
	return a.x>b.x;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].pos=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int xx=1,yy=1,len=1;
	int ex=(m&1?n:1),ey=(m&1?m:n);
//	cout<<ex<<" "<<ey<<"\n";
	while(1){
		//
		if(a[len].pos==1){
			r=xx;
			c=yy;
			break;
		}
		//
		if(xx==ex&&yy==ey)break;
		while(xx<n){
			++xx,++len;
			if(a[len].pos==1){
				r=xx;
				c=yy;
				break;
			}
		}
		if(xx==ex&&yy==ey)break;
		//
		if(r!=-1&&c!=-1)break;
		++yy;
		++len;
		if(a[len].pos==1){
			r=xx;
			c=yy;
			break;
		}
		if(xx==ex&&yy==ey)break;
		//
		while(xx>1){
			--xx,++len;
			if(a[len].pos==1){
				r=xx;
				c=yy;
				break;
			}
		}
		if(xx==ex&&yy==ey)break;
		//
		++yy;
		++len;
		if(a[len].pos==1){
			r=xx;
			c=yy;
			break;
		}
		if(xx==ex&&yy==ey)break;
		if(r!=-1&&c!=-1)break;
	}
	cout<<c<<" "<<r;
	return 0;
}
