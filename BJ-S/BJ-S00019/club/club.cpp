#include<bits/stdc++.h>
using namespace std;
long long t,n,ren[100005],bm[5];
struct node{
    long long x,y,z,idx,idy,idz;
}xcy[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        bm[1]=bm[2]=bm[3]=0;
        long long maxx=n/2;
        for(int i=1;i<=n;i++){
            cin>>xcy[i].x>>xcy[i].y>>xcy[i].z;
            xcy[i].idx=0;
            xcy[i].idy=0;
            xcy[i].idz=0;
            if(xcy[i].x>=xcy[i].y)xcy[i].idx++;
            if(xcy[i].x>=xcy[i].z)xcy[i].idx++;
            if(xcy[i].y>=xcy[i].x)xcy[i].idy++;
            if(xcy[i].y>=xcy[i].z)xcy[i].idy++;
            if(xcy[i].z>=xcy[i].x)xcy[i].idz++;
            if(xcy[i].z>=xcy[i].y)xcy[i].idz++;
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
			if(xcy[i].idx==2){
                bm[1]++;
                ans+=xcy[i].x;
			}
			else if(xcy[i].idy==2){
                bm[2]++;
                ans+=xcy[i].y;
			}
			else{
                bm[3]++;
                ans+=xcy[i].z;
			}

		}
		long long xh=200005,xhh,idxh;
            while(bm[1]>maxx){
                xh=200005;
                for(int i=1;i<=n;i++){
                    xhh=xh;
                    if(xcy[i].idx==2){
                        xh=min(min(xcy[i].x-xcy[i].y,xh),xcy[i].x-xcy[i].z);
                        if(xh!=xhh)idxh=i;
                    }
                }
                ans-=xh;
                xcy[idxh].idx=1;
                bm[1]--;
            }
            while(bm[2]>maxx){
                xh=200005;

                for(int i=1;i<=n;i++){
                    xhh=xh;
                    if(xcy[i].idy==2){
                        xh=min(min(xcy[i].y-xcy[i].x,xh),xcy[i].y-xcy[i].z);
                        if(xh!=xhh)idxh=i;
                    }
                    if(xh!=xhh)idxh=i;
                }
                ans-=xh;
                xcy[idxh].idy=1;
                bm[2]--;
            }
            while(bm[3]>maxx){
                xh=200005;
                for(int i=1;i<=n;i++){
                    xhh=xh;
                    if(xcy[i].idz==2){
                        xh=min(min(xcy[i].z-xcy[i].x,xh),xcy[i].z-xcy[i].y);
                        if(xh!=xhh)idxh=i;
                    }
                    if(xh!=xhh)idxh=i;
                }
                xcy[idxh].idz=1;
                ans-=xh;
                bm[3]--;

            }
		cout<<ans<<endl;
    }
    return 0;
}
