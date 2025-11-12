#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b,c;
}h[100001];
bool cmp(node x,node y){
    return max(x.a,max(x.b,x.c))>max(y.a,max(y.b,y.c));
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t;
    int ca,cb,cc,ans,a,b,c;
    while(t--){
        cin>>n;
        ca=cb=cc=ans=0;
        for(int i=1;i<=n;i++){
            cin>>h[i].a>>h[i].b>>h[i].c;
        }
        sort(h+1,h+n+1,cmp);
        for(int i=1;i<=n;i++){
            a=h[i].a,b=h[i].b,c=h[i].c;
            if(a>b && a>c){
                if(ca<n/2){
                    ca++;
                    ans+=a;
                }else{
                    if(b>c){
                        cb++;
                        ans+=b;
                    }else{
                        cc++;
                        ans+=c;
                    }
                }

            }else if(b>a && b>c){
                if(cb<n/2){
                    cb++;
                    ans+=b;
                }else{
                    if(a>c){
                        ca++;
                        ans+=a;
                    }else{
                        cc++;
                        ans+=c;
                    }
                }
            }else{
                if(cc<n/2){
                    cc++;
                    ans+=c;
                }else{
                    if(a>b){
                        ca++;
                        ans+=a;
                    }else{
                        cb++;
                        ans+=b;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
