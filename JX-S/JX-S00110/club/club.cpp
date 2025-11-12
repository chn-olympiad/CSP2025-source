#include <bits/stdc++.h>
using namespace std;
struct node{
    long long a,b,c;
}x[100005];
long long n,t,aa,bb,cc,sum;
long long a1[100005],b1[100005],c1[100005];
void ga(){
    sort(a1+1,a1+1+aa);
    for(int i=aa;i>n/2;i--){
        sum+=a1[i];
    }
}
void gb(){
    sort(b1+1,b1+1+bb);
    for(int i=bb;i>n/2;i--){
        sum+=b1[i];
    }
}
void gc(){
    sort(c1+1,c1+1+cc);
    for(int i=cc;i>n/2;i--){
        sum+=c1[i];
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        sum=aa=bb=cc=0;
        for(long long i=1;i<=n;i++){
            cin>>x[i].a>>x[i].b>>x[i].c;
        }
        for(long long i=1;i<=n;i++){
            if(x[i].a>x[i].b&&x[i].a>x[i].c){
                a1[++aa]=max((x[i].b-x[i].a),(x[i].c-x[i].a));
                sum+=x[i].a;
            }else if(x[i].b>x[i].a&&x[i].b>x[i].c){
                b1[++bb]=max((x[i].a-x[i].b),(x[i].c-x[i].b));
                sum+=x[i].b;
            }else{
                c1[++cc]=max((x[i].b-x[i].c),(x[i].a-x[i].c));
                sum+=x[i].c;
            }
        }
        if(aa>(n/2)){
            ga();
        }
        if(bb>(n/2)){
            gb();
        }
        if(cc>(n/2)){
            gc();
        }
        cout<<sum<<endl;
    }
    return 0;
}
