#include<bits/stdc++.h>
using namespace std;
struct abc{
    int a,b,c;
};
bool cmp(abc x,abc y){
    return max({x.a,x.b,x.c})>max({y.a,y.b,y.c});

}
int n;
int main(){
    int t;
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        abc a[100010];
        for(int i=1;i<=n;i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
        }
        sort(a+1,a+1+n,cmp);
        int ca=0,cb=0,cc=0,cut=0;
        for(int i=1;i<=n;i++){
            abc z=a[i];
            if(z.a>=z.b){
                if(z.b>=z.c){
                    if(ca<n/2){
                        ca++;
                        cut+=z.a;
                    }
                    else if(cb<n/2){
                        cb++;
                        cut+=z.b;
                    }
                    else{
                        cc++;
                        cut+=z.c;
                    }

                }
                else if(z.c>=z.b){
                    if(ca<n/2){
                        ca++;
                        cut+=z.a;
                    }
                    else if(cc<n/2){
                        cc++;
                        cut+=z.c;
                    }
                    else{
                        cb++;
                        cut+=z.b;
                    }
                }
            }
            else if(z.b>=z.a){
                if(z.a>=z.c){
                    if(cb<n/2){
                        cb++;
                        cut+=z.b;
                    }
                    else if(ca<n/2){
                        ca++;
                        cut+=z.a;
                    }
                    else{
                        cc++;
                        cut+=z.c;
                    }

                }
                else if(z.c>=z.a){
                    if(cb<n/2){
                        cb++;
                        cut+=z.b;
                    }
                    else if(cc<n/2){
                        cc++;
                        cut+=z.c;
                    }
                    else{
                        ca++;
                        cut+=z.a;
                    }
                }
            }
            else if(z.c>z.a){
                if(z.a>z.b){
                    if(cc<n/2){
                        cc++;
                        cut+=z.c;
                    }
                    else if(ca<n/2){
                        ca++;
                        cut+=z.a;
                    }
                    else{
                        cb++;
                        cut+=z.b;
                    }

                }
                else if(z.b>z.a){
                    if(cc<n/2){
                        cc++;
                        cut+=z.c;
                    }
                    else if(cb<n/2){
                        cb++;
                        cut+=z.b;
                    }
                    else{
                        ca++;
                        cut+=z.a;
                    }

                }
            }
        }
        cout<<cut<<endl;
    }
    return 0;
}
