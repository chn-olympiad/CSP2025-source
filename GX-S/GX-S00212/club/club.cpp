#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
const int maxn=1e6+10;

struct anbeniya{
    int mx,se,ed;
    int s1,s2,s3;
    int sum;
}awa[maxn];

bool cmp1(anbeniya x,anbeniya y){
    if(x.mx==y.mx){
        if(x.se==y.se) return x.ed>y.ed;
        else return x.se>y.se;
    }
    else return x.mx>y.mx;
}


bool cmp2(anbeniya x,anbeniya y){
    if(x.mx==y.mx){
        if(x.se==y.se) return x.ed<y.ed;
        else return x.se<y.se;
    }
    else return x.mx<y.mx;
}


int t;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int m;
        cin>>m;
        for(int i=1;i<=m;i++){
            cin>>awa[i].s1>>awa[i].s2>>awa[i].s3;
            awa[i].mx=max(max(awa[i].s1,awa[i].s2),max(awa[i].s2,awa[i].s3));
            awa[i].ed=min(min(awa[i].s1,awa[i].s2),min(awa[i].s2,awa[i].s3));
            awa[i].se=awa[i].s1+awa[i].s2+awa[i].s3-awa[i].mx-awa[i].ed;
            awa[i].sum=awa[i].s1+awa[i].s2+awa[i].s3;
        }
        sort(awa+1,awa+1+m,cmp2);
        int p1=m/2,p2=m/2,p3=m/2;
        int f1=0,f2=0,f3=0;

        //start to chose
        for(int i=1;i<=m;i++) {

            //choce1
            if(awa[i].mx==awa[i].s1) {
                if(p1>0) {
                    p1--;
                    f1+=awa[i].s1;
                }
                else{
                    if(awa[i].se==awa[i].s2){
                        if(p2>0){
                            p2--;
                            f2+=awa[i].s2;
                        }
                        else{
                            p3--;
                            f3+=awa[i].s3;
                        }
                    }
                }
            }
            //chose2
            else if(awa[i].mx==awa[i].s2) {
                if(p2>0) {
                    p2--;
                    f2+=awa[i].s2;
                }
                else{
                    if(awa[i].se==awa[i].s1){
                        if(p1>0){
                            p1--;
                            f1+=awa[i].s1;
                        }
                        else{
                            p3--;
                            f3+=awa[i].s3;
                        }
                    }
                }
            }
            //chose3
            else{
                if(p3>0) {
                    p3--;
                    f3+=awa[i].s3;
                }
                else{
                    if(awa[i].se==awa[i].s1){
                        if(p1>0){
                            p1--;
                            f1+=awa[i].s1;
                        }
                        else{
                            p2--;
                            f2+=awa[i].s2;
                        }
                    }
                }
            }
        }
        int ans1=f1+f2+f3;


        sort(awa+1,awa+1+m,cmp1);
        p1=m/2,p2=m/2,p3=m/2;
        f1=0,f2=0,f3=0;

        //start to chose2
        for(int i=1;i<=m;i++) {

            //choce1
            if(awa[i].mx==awa[i].s1) {
                if(p1>0) {
                    p1--;
                    f1+=awa[i].s1;
                }
                else{
                    if(awa[i].se==awa[i].s2){
                        if(p2>0){
                            p2--;
                            f2+=awa[i].s2;
                        }
                        else{
                            p3--;
                            f3+=awa[i].s3;
                        }
                    }
                }
            }
            //chose2
            else if(awa[i].mx==awa[i].s2) {
                if(p2>0) {
                    p2--;
                    f2+=awa[i].s2;
                }
                else{
                    if(awa[i].se==awa[i].s1){
                        if(p1>0){
                            p1--;
                            f1+=awa[i].s1;
                        }
                        else{
                            p3--;
                            f3+=awa[i].s3;
                        }
                    }
                }
            }
            //chose3
            else{
                if(p3>0) {
                    p3--;
                    f3+=awa[i].s3;
                }
                else{
                    if(awa[i].se==awa[i].s1){
                        if(p1>0){
                            p1--;
                            f1+=awa[i].s1;
                        }
                        else{
                            p2--;
                            f2+=awa[i].s2;
                        }
                    }
                }
            }
        }

        int ans2=f1+f2+f3;
        cout<<max(ans1,ans2)<<endl;
    }
    return 0;
}
