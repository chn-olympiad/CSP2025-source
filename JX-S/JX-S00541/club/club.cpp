#include<bits/stdc++.h>
using namespace std;
long long n,ans,x,y,z,_[1101011],cnt,T;
struct node{
    long long a,b,c,d;
}xy[1101011];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    for(int j=1;j<=T;j++){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>xy[i].a>>xy[i].b>>xy[i].c;
            if(xy[i].a>=xy[i].b&&xy[i].a>=xy[i].c){
                ans+=xy[i].a;
                xy[i].d=1;
                x++;
            }else if(xy[i].b>=xy[i].a&&xy[i].b>=xy[i].c){
                ans+=xy[i].b;
                xy[i].d=2;
                y++;
            }else{
                ans+=xy[i].c;
                xy[i].d=3;
                z++;
            }
        }
        if(x>(n/2)){
            for(int i=1;i<=n;i++){
                if(xy[i].d==1){
                    cnt++;
                    _[cnt]=xy[i].a-max(xy[i].b,xy[i].c);
                }
            }
            sort(_+1,_+cnt+1);
            for(int i=1;i<=x-(n/2);i++){
                ans-=_[i];
            }
        }else if(y>(n/2)){
            for(int i=1;i<=n;i++){
                if(xy[i].d==2){
                    cnt++;
                    _[cnt]=xy[i].b-max(xy[i].a,xy[i].c);
                }
            }
            sort(_+1,_+cnt+1);
            for(int i=1;i<=y-(n/2);i++){
                ans-=_[i];
            }
        }else{
            for(int i=1;i<=n;i++){
                if(xy[i].d==3){
                    cnt++;
                    _[cnt]=xy[i].c-max(xy[i].b,xy[i].a);
                }
            }
            sort(_+1,_+cnt+1);
            for(int i=1;i<=z-(n/2);i++){
                ans-=_[i];
            }
        }
        cout<<ans<<"\n";
        ans=0;
        cnt=0;
        x=0;
        y=0;
        z=0;
    }
    return 0;
}
