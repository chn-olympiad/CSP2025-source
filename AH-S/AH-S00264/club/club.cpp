#include<bits/stdc++.h>
using namespace std;
struct ren{
    int x,y,z;
    int mx,mn,dt,mxid;
}a[100005];
int n,m,k,tot,sx,sy,sz;
long long ans;
bool cmp(ren A,ren B){
    return A.dt<B.dt;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T; scanf("%d",&T);
    while(T--){
	ans=sx=sy=sz=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
	    scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	    a[i].mx=max(a[i].x,max(a[i].y,a[i].z));
	    if(a[i].mx==a[i].x){
		sx++;
		a[i].mxid=1;
	    }
	    else if(a[i].mx==a[i].y){
		sy++;
		a[i].mxid=2;
	    }
	    else if(a[i].mx==a[i].z){
		sz++;
		a[i].mxid=3;
	    }
	    a[i].mn=min(a[i].x,min(a[i].y,a[i].z));
	    /*if(a[i].mn==a[i].x){
		a[i].mnid=1;
	    }
	    if(a[i].mn==a[i].y){
		a[i].mnid=2;
	    }
	    if(a[i].mn==a[i].z){
		a[i].mnid=3;
	    }*/
	    ans+=a[i].mx;
	    a[i].dt=a[i].mx*2-a[i].x-a[i].y-a[i].z+a[i].mn;
	}
	stable_sort(a+1,a+1+n,cmp);
	int ex=0,mk=0;
	if(sx*2>n){
	    ex=sx-n/2;
	    mk=1;
	}
	else if(sy*2>n){
	    ex=sy-n/2;
	    mk=2;
	}
	else if(sz*2>n){
	    ex=sz-n/2;
	    mk=3;
	}
	for(int i=1;i<=n;i++){
	    if(ex==0) break;
	    if(a[i].mxid==mk){
		ex--;
		ans-=a[i].dt;
		
	    }
	}
	cout<<ans<<'\n';
    }
    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
