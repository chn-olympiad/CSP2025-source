#include<bits/stdc++.h>
using namespace std;
int num[5];
struct M{
    int a,b,c,d;
}aa[100005];
bool cmp(M x,M y){
    if(x.a<y.a) return x.a>y.a;
    else if(x.b<y.b) return x.b>y.b;
    else  if(x.c<y.c) return x.c>y.c;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,sum=0;
        cin>>n;
        int m=n/2;
        for(int i=1;i<=n;i++){
            cin>>aa[i].a>>aa[i].b>>aa[i].c;
            if(aa[i].a>aa[i].b){
                aa[i].d=1;
                if(aa[i].c>aa[i].a) aa[i].d=3;
            }
            else{
                aa[i].d=2;
                if(aa[i].c>aa[i].b) aa[i].d=3;
            }
        }
        sort(aa+1,aa+n+1,cmp);
        for(int i=1;i<=n;i++){
            bool numm=0;
            while(!numm){
            if(aa[i].d==1){
                if(num[1]==m){
                    if(aa[i].b>aa[i].c){
                        aa[i].d=2;
                    }
                    else aa[i].d=3;
                    continue;
                }
                sum+=aa[i].a;
                num[1]++;
                numm=1;
            }
            if(aa[i].d==2){
                if(num[2]==m){
                    if(aa[i].a>aa[i].c && num[1]<m){
                        aa[i].d=1;
                    }

                    else aa[i].d=3;
                    continue;
                }
                sum+=aa[i].b;
                num[2]++;
                numm=1;
            }
            if(aa[i].d==3){
                if(num[3]==m){
                    if(aa[i].b>aa[i].a && num[2]<m){
                        aa[i].d=2;
                    }

                    else aa[i].d=1;
                    continue;
                }
                sum+=aa[i].c;
                num[3]++;
                numm=1;
            }
            }
        }
        cout<<sum;
    }
    return 0;
}
