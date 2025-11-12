#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y,z,p;
}a[100005],b[100005],c[100005],d[100005];
int t,n,totb,totc,totd;
long long ans;
bool cmp(node e,node f){
    return e.p>f.p;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        totb=totc=totd=ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				a[i].p=a[i].x-max(a[i].y,a[i].z);
                totb++;
                b[totb].x=a[i].x;
                b[totb].y=a[i].y;
                b[totb].z=a[i].z;
                b[totb].p=a[i].p;
            }
            else if(a[i].y>=a[i].z&&a[i].y>=a[i].x){
				a[i].p=a[i].y-max(a[i].x,a[i].z);
                totc++;
                c[totc].x=a[i].x;
                c[totc].y=a[i].y;
                c[totc].z=a[i].z;
                c[totc].p=a[i].p;
            }
            else if(a[i].z>=a[i].y&&a[i].z>=a[i].x){
				a[i].p=a[i].z-max(a[i].y,a[i].x);
                totd++;
                d[totd].x=a[i].x;
                d[totd].y=a[i].y;
                d[totd].z=a[i].z;
                d[totd].p=a[i].p;
            }
        }
        for(int i=1;i<=totb;i++){
            ans+=b[i].x;
        }
        for(int i=1;i<=totc;i++){
            ans+=c[i].y;
        }
        for(int i=1;i<=totd;i++){
            ans+=d[i].z;
        }
        if(totb>n/2){
            sort(b+1,b+totb+1,cmp);
            for(int i=n/2+1;i<=totb;i++){
                ans-=b[i].p;
            }
        }
        if(totc>n/2){
            sort(c+1,c+totc+1,cmp);
            for(int i=n/2+1;i<=totc;i++){
                ans-=c[i].p;
            }
        }
        if(totd>n/2){
            sort(d+1,d+totd+1,cmp);
            for(int i=n/2+1;i<=totd;i++){
                ans-=d[i].p;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
