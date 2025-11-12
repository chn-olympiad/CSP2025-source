#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
   cin>>t;
   for(int g=0;g<t;g++){
    int n,x=0,y=0,z=0,ans=0,xy=0,xz=0,yz=0,ansa=0,xysame=0,yzsame=0,xzsame=0;
    cin>>n;
    int s=n/2;
    int p[3*n];
    for(int i=0;i<3*n;i++){
        cin>>p[i];

    }
   for(int i=0;i<3*n;i+=3){
        int k=max(p[i],max(p[i+1],p[i+2]));
        ans+=k;
        //cout<<k<<" ";
        if(k==p[i]){
            if(k==p[i+1]){
                 xysame++;
            }
            if(k==p[i+2]) {
                    xzsame++;
            }
            x++;
        }
         if(k==p[i+1]){
             if(k==p[i+2]) {
                    yzsame++;
             }
            y++;
        }
         if(k==p[i+2]){
            z++;
        }
    }
    //cout<<ans;
    //cout<<s<<" "<<x<<" "<<y<<" "<<z<<" ";
    if(x<=s && y<=s &&z <=s){
        cout<<ans<<endl;
    }
     else if(x>s){
            x=x-xysame-xzsame;
            y=y-yzsame;
            //cout<<x<<" "<<y<<" "<<z<<" ";
            if(x>s){
        while(x>s){
            int i=0;
            int xymin=100000000,xyans;
            while(i+3<3*n){
            xy=p[i]-p[i+1];
            if(xy>=0&&xy<=xymin){
            xymin=xy;
            xyans=i;
            }
            i+=3;
            }
            ans-=xymin;
            p[xyans]=-1;
            y++;
            x--;
            //cout<<y<<" ";
            //cout<<ans<<" ";
        }
        while(y>s){
            int i=0;
            int yzmin=100000000,yzans;
            while(i+3<3*n){
            yz=p[i]-p[i+1];
            if(yz>=0&&yz<=yzmin){
            yzmin=yz;
            yzans=i;
            }
            i+=3;
            }
            //cout<<ans<<" ";
            ans-=yzmin;
            p[yzans]=-1;
            z++;
            y--;
        }
    }
        cout<<ans<<endl;
    }
    else if(y>s){
            y=y-xysame-yzsame;
            x=x-xzsame;
            if(y>s){
            //cout<<x<<" "<<y<<" "<<z<<" ";
        while(y>s){
            int i=0;
            int xymin=100000000,xyans;
            while(i+3<=3*n){
            xy=p[i+1]-p[i];
            if(xy>=0&&xy<=xymin){
            xymin=xy;
            xyans=i+1;
            }
            i+=3;
            }
            ans-=xymin;
            p[xyans]=-1;
            y--;
            x++;
        }
        while(x>s){
            int i=0;
            int xzmin=100000000,xzans;
            while(i+3<=3*n){
            xz=p[i]-p[i+2];
            if(xz>=0&&xz<=xzmin){
            xzmin=xz;
            xzans=i;
            }
            i+=3;
            }
            ans-=xzmin;
            p[xzans]=-1;
            z++;
            x--;

        }
    }
        cout<<ans<<endl;
    }
     else if(z>s){
            z=z-xzsame-yzsame;
            x=x-xysame;
            if(z>s){
        while(z>s){
            int i=0;
            int xzmin=100000000,xzans;
            while(i+3<3*n){
            xz=p[i+2]-p[i];
            if(xz>=0&&xz<=xzmin){
            xzmin=xz;
            xzans=i+2;
            }
            i+=3;
            }
           //cout<<ans;
            ans-=xzmin;
            p[xzans]=-1;
            z--;
            x++;
        }
        while(x>s){
            int i=0;
            int xymin=100000000,xyans;
            while(i+3<=3*n){
            xz=p[i]-p[i+1];
            if(xy>=0&&xy<=xymin){
            xymin=xy;
            xyans=i;
            }
            i+=3;
            }
            ans-=xymin;
            p[xyans]=-1;
            y++;
            x--;

        }
            }
        cout<<ans<<endl;
    }
   }
   return 0;
}
