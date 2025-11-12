#include<bits/stdc++.h>
using namespace std;
int t;
struct node{
    int a,b,c,d,e;
}x[100010];
bool cmp(node aa,node bb){
    return aa.d<bb.d;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        int xx=0,yy=0,zz=0;
        int n=0;
        cin>>n;
        int ans=0;

        for(int i=1;i<=n;i++){
            cin>>x[i].a>>x[i].b>>x[i].c;
            if(x[i].a>=x[i].b&&x[i].a>=x[i].c){
                if(x[i].b>=x[i].c){
                    x[i].d=x[i].a-x[i].b;
                }
                else{
                    x[i].d=x[i].a-x[i].c;
                }
                xx++;
                ans+=x[i].a;
                x[i].e=1;
            }
            else if(x[i].b>=x[i].a&&x[i].b>=x[i].c){
                if(x[i].a>=x[i].c){
                    x[i].d=x[i].b-x[i].a;
                }
                else{
                    x[i].d=x[i].b-x[i].c;
                }
                yy++;
                ans+=x[i].b;
                x[i].e=2;
            }
            else if(x[i].c>=x[i].a&&x[i].c>=x[i].b){
                if(x[i].a>=x[i].b){
                    x[i].d=x[i].c-x[i].a;
                }
                else{
                    x[i].d=x[i].c-x[i].b;
                }
                zz++;
                ans+=x[i].c;
                x[i].e=3;
            }
        }
        sort(x+1,x+1+n,cmp);

        if(xx>n/2){
            for(int i=1;i<=xx-n/2;i++){
                if(x[i].e==1){
                   ans-=x[i].d;
                }
                else{
                    xx++;
                }
            }
        }
        else if(yy>n/2){
            for(int i=1;i<=yy-n/2;i++){
                if(x[i].e==2){
                   ans-=x[i].d;
                }
                else{
                    yy++;
                }
            }

        }
        else if(zz>n/2){
            for(int i=1;i<=zz-n/2;i++){
                if(x[i].e==3){
                   ans-=x[i].d;
                }
                else{
                    zz++;
                }
            }

        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*
10
2020 14533 18961  3
2423 15344 16322  3 111
1910 6224 16178  3
2038 9963 19722  3  222
8375 10557 5444  2
3518 14615 17976  3
6188 13424 16615  3  333
8769 509 4394  1
958 3195 9953  3
16441 5313 10926  1

147325
151494-978-3191
*/



