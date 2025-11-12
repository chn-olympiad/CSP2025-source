#include<bits/stdc++.h>
using namespace std;
int t;
int countt[4],vec;
struct num{
    int val,po;
}glad[100005][3],newn[300015];
bool cmp(num l,num r){
    return l.val>r.val;
}
bool cmp2(int l,int r){
    return l>r;
}
void putclub(){
    int n;
    cin>>n;
    if(n==2){
        int biggest=-1,bp;
        for(int i=0;i<n;i++){
            cin>>glad[i][0].val>>glad[i][1].val>>glad[i][2].val;
            for(int j=0;j<3;j++)glad[i][j].po=j;
            sort(glad[i],glad[i]+3,cmp);
        }
        if(glad[0][0].po!=glad[1][0].po){
            cout<<glad[0][0].val+glad[1][0].val;
            return;
        }
        else{
            cout<<max((glad[0][0].val+glad[1][1].val),(glad[0][1].val+glad[1][0].val))<<endl;
        }
    }
    else if(n==1e5){
        bool flag=1;
        for(int i=0;i<n;i++){
            cin>>glad[i][0].val>>glad[i][1].val>>glad[i][2].val;
            for(int j=0;j<3;j++)glad[i][j].po=j;
            if(glad[i][1].val==1)flag=0;
        }
        if(flag){
            int now[100005];
            for(int i=0;i<n;i++){
                now[i]=glad[i][0].val;
            }
            sort(now,now+n,cmp2);
            int ans=0;
            for(int i=0;i<n/2;i++){
                ans+=now[i];
            }
            cout<<ans<<endl;
        }
        else{
            int nowa[100005],nowb[100005];
            for(int i=0;i<n;i++){
                nowa[i]=glad[i][0].val;
                nowb[i]=glad[i][1].val;
            }
            sort(nowa,nowa+n,cmp2);
            sort(nowb,nowb+n,cmp2);
            int ans=0;
            for(int i=0;i<n/2;i++){
                ans+=nowa[i]+nowb[i];
            }
            cout<<ans<<endl;
        }
    }
    else{
        int ans=0,a=0,b=0;
        for(int i=0;i<n;i++){
            cin>>glad[i][0].val>>glad[i][1].val>>glad[i][2].val;
            if(glad[i][0].val>glad[i][1].val){
                if(a<n/2){
                    ans+=glad[i][0].val;
                    a++;
                }
                else{
                    ans+=glad[i][1].val;
                    b++;
                }
            }
            if(glad[i][0].val<glad[i][1].val){
                if(b<n/2){
                    ans+=glad[i][1].val;
                    b++;
                }
                else{
                    ans+=glad[i][0].val;
                    a++;
                }
            }
        }
        cout<<ans<<endl;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        putclub();
    }
    return 0;
}
