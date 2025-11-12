#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b,c;
}l[100005];
int t,n,c1,c2,c3;
long long sum;
bool cmp(node x,node y){
    return 2*max(x.a,max(x.b,x.c))+min(x.a,min(x.b,x.c))-x.a-x.b-x.c>2*max(y.a,max(y.b,y.c))+min(y.a,min(y.b,y.c))-y.a-y.b-y.c;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        sum=0,c1=0,c2=0,c3=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>l[i].a>>l[i].b>>l[i].c;
        }
        sort(l+1,l+1+n,cmp);
        for(int i=1;i<=n;i++){
            node h=l[i];
            if(h.a>=h.b&&h.a>=h.c){
                if(c1==n/2){
                    if(h.b>h.c){
                        sum+=h.b;
                    }else{
                        sum+=h.c;
                    }
                }else{
                    c1++;
                    sum+=h.a;
                }
            }else if(h.b>=h.a&&h.b>=h.c){
                if(c2==n/2){
                    if(h.a>h.c){
                        sum+=h.a;
                    }else{
                        sum+=h.c;
                    }
                }else{
                    c2++;
                    sum+=h.b;
                }
            }else{
                if(c3==n/2){
                    if(h.b>h.a){
                        sum+=h.b;
                    }else{
                        sum+=h.a;
                    }
                }else{
                    c3++;
                    sum+=h.c;
                }
            }
        }
        cout<<sum<<'\n';
    }
    return 0;
}
