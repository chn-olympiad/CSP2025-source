#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct featt{
    int fi,se,th,maxx,loc;
};
bool cmp(featt x,featt y){
    return x.maxx>y.maxx;
}
int t;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int oo=1;oo<=t;oo++){
        int n;
        featt a[N];
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i].fi;
            cin>>a[i].se;
            cin>>a[i].th;
            a[i].maxx=max(a[i].fi,max(a[i].se,a[i].th));
            if(a[i].fi==a[i].maxx) a[i].loc=1;
            if(a[i].se==a[i].maxx) a[i].loc=2;
            if(a[i].th==a[i].maxx) a[i].loc=3;
        }
        sort(a,a+n+1,cmp);
        long long sum=0;
        int b[4]={0,0,0,0};
        for(int i=0;i<n;i++){
            if(b[a[i].loc]<(n/2)){
                b[a[i].loc]++;
                sum+=a[i].maxx;
            }
            else{
                int maxx2;
                if(a[i].loc==1){
                    if(a[i].se>=a[i].th&&b[2]<(n/2)){
                    sum+=a[i].se;
                    b[2]++;
                    }
                    else{
                        sum+=a[i].th;
                        b[3]++;
                    }
                }
                if(a[i].loc==2){
                    if(a[i].fi>=a[i].th&&b[1]<(n/2)){
                    sum+=a[i].fi;
                    b[1]++;
                    }
                    else{
                        sum+=a[i].th;
                        b[3]++;
                    }
                }
                if(a[i].loc==3){
                    if(a[i].se>=a[i].fi&&b[2]<(n/2)){
                    sum+=a[i].se;
                    b[2]++;
                    }
                    else{
                        sum+=a[i].fi;
                        b[1]++;
                    }
                }
            }
        }
        cout<<sum<<'\n';
    }
    return 0;
}
