#include <bits/stdc++.h>
using namespace std;
int t,n;
struct CL{
    int x,y,z;
}a[100005];
bool cmp1(CL b,CL c){
    return b.x>c.x;
}
bool cmp2(CL d,CL e){
    return d.y<e.y;
}
bool cmp3(CL f,CL g){
    return f.z<g.z;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
        }
        if(a[1].y==a[1].z==0){
            sort(a+1,a+n+1,cmp1);
            cout<<a[1].x;
            continue;
        }
        if(a[1].z==0){
            int maxx1=-1,maxx2=-1,maxy1=-1,maxy2=-1,maxs1,maxs2,mays1,mays2;
            for(int i=1;i<=n;i++){
                if(a[i].x>maxx1){
                    maxx1=a[i].x;
                    maxs1=i;
                }
                else if(a[i].x>maxx2){
                    maxx2=a[i].x;
                    maxs2=i;
                }
                if(a[i].y>maxy1){
                    maxy1=a[i].y;
                    mays1=i;
                }
                else if(a[i].y>maxy2){
                    maxy2=a[i].y;
                    mays2=i;
                }
            }
            if(maxx1!=maxy1){
                cout<<maxx1+maxy1;
            }
            else{
                cout<<max(maxx1+maxy2,maxx2+maxy1);
            }
            continue;
        }
        //long long ans;
        //int mx1=-1,my1=-1,mz1=-1,mx2=-1,my2=-1,mz2=-1,mx3=-1,my3=-1,mz3=-1;
        //int xx1,xx2,xx3,xy1,xy2,xy3,xz1,xz2,xz3;
        //for(int i=1;i<=n;i++){
            //if(a[i].x>mx1){
                //mx1=a[i].x;
                //xx1=i;
            //}
            //else if(a[i].x>mx2){
                //mx2=a[i].x;
                //xx2=i;
            //}
            //else if(a[i].x>mx3){
                //mx3=a[i].x;
                //xx3=i;
            //}
            //if(a[i].y>my1){
                //my1=a[i].y;
                //xy1=i;
            //}
            //else if(a[i].y>my2){
               // my2=a[i].y;
                //xy2=i;
            //}
            //else if(a[i].y>my3){
                //my3=a[i].y;
                //xy3=i;
            //}
            //if(a[i].z>mz1){
                //mz1=a[i].z;
                //xz1=i;
            //}
            //else if(a[i].z>mz2){
              //  mz2=a[i].z;
                //xz2=i;
            //}
            //else if(a[i].z>mz3){
              //  mz3=a[i].z;
                //xz3=i;
            //}
        //}
        //if(xx1!=xy1&&xy1!=xz1&&xz1!=xx1){
          //  ans=mx1+my1+mz1;
        //}
        //else if(xx1==xy1){
          //  if(mx1+my2>my1+mx2){
            //    ans=mx1+my2+mz1;
            //}
            //else{
              //  ans=mx2+my1+mz1;
            //}
        //}
        //else if(xx1==xz1){
          //  if(mx1+mz2>mz1+mx2){
            //    ans=mx1+mz2+my1;
            //}
            //else{
              //  ans=mx2+my1+mz1;
            //}
        //}
        //else if(xz1==xy1){
          //  if(my1+mz2>mz1+my2){
            //    ans=mx1+my1+mz2;
            //}
            //else{
              //  ans=my2+mx1+mz1;
            //}
        //}
        //cout<<ans;
        if(n==1){
            cout<<max(a[1].x,max(a[1].y,a[1].z));
        }
        else if(n<=2){
            int ma=max(a[1].x,max(a[1].y,a[1].z));
            int mb=max(a[2].x,max(a[2].y,a[2].z));
            cout<<ma+mb;
        }
        else{
            int ans;
            sort(a+1,a+n+1,cmp1);
            ans+=a[1].x;
            sort(a+1,a+n+1,cmp2);
            ans+=a[1].y;
            sort(a+1,a+n+1,cmp3);
            ans+=a[1].z;
            cout<<ans;
        }
    }
    return 0;
}