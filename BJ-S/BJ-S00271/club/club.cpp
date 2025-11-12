#include<bits/stdc++.h>
using namespace std;
int t,n,mx1,mx2,mx3;
struct le{
    int a1,a2,a3;
//    friend bool operator <(le x,le y){if(max({x.a1,x.a2,x.a3})!=max({y.a1,y.a2,y.a3}))return max({x.a1,x.a2,x.a3})>max({y.a1,y.a2,y.a3});}
}a[100100];
int md(int x,int y,int z){
    if(max(y,z)>=x&&x>=min(y,z))return x;
    if(max(y,x)>=z&&z>=min(y,x))return z;
    if(max(x,z)>=y&&y>=min(z,x))return y;
}
bool cmp(le x,le y){
    int xx=max({x.a1,x.a2,x.a3}),yy=max({y.a1,y.a2,y.a3});
    if(xx-md(x.a1,x.a2,x.a3)!=yy-md(y.a1,y.a2,y.a3))return xx-md(x.a1,x.a2,x.a3)>yy-md(y.a1,y.a2,y.a3);
    if(xx!=yy)return xx>yy;
    return md(x.a1,x.a2,x.a3)>md(y.a1,y.a2,y.a3);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        mx1=mx2=mx3=0;
        long long ans=0;
        cin>>n;
        int hn=n/2;
        for(int i=1;i<=n;i++){
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++){
            int x=a[i].a1,y=a[i].a2,z=a[i].a3;
            int mx=max({x,y,z}),mid=md(x,y,z);
            if(mx==x){
                if(mx1<hn)mx1++,ans+=x;
                else{
                    if(mid==y){
                        mx2++,ans+=y;
                    }else{
                        mx3++,ans+=z;
                    }
                }
            }else if(mx==y){
                if(mx2<hn)mx2++,ans+=y;
                else{
                    if(mid==x){
                        mx1++,ans+=x;
                    }else{
                        mx3++,ans+=z;
                    }
                }
            }else{
                if(mx3<hn)mx3++,ans+=z;
                else{
                    if(mid==y){
                        mx2++,ans+=y;
                    }else{
                        mx1++,ans+=x;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
