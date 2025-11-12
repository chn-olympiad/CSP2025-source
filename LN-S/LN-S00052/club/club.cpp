#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long T,n,p1,p2,p3,sum,ma;
long long r1[N],r2[N],r3[N];
struct u{
    long long a,b,c,f,mi,k;
}e[N];
bool cmp(u x,u y){
    if(x.k!=y.k)return x.k<y.k;
    else return x.mi<y.mi;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        p1=p2=p3=sum=0;
        for(long long i=1;i<=n;i++){
            cin>>e[i].a>>e[i].b>>e[i].c;
            if(max(e[i].a,max(e[i].b,e[i].c))==e[i].a){
                    p1++,sum+=e[i].a,e[i].k=1;
                    if(e[i].b>=e[i].c)e[i].mi=e[i].a-e[i].b,e[i].f=2;
                    else e[i].mi=e[i].a-e[i].c,e[i].f=3;
            }
            else if(max(e[i].a,max(e[i].b,e[i].c))==e[i].b){
                    p2++,sum+=e[i].b,e[i].k=2;
                    if(e[i].a>=e[i].c)e[i].mi=e[i].b-e[i].a,e[i].f=1;
                    else e[i].mi=e[i].b-e[i].c,e[i].f=3;
            }
            else {
                    p3++,sum+=e[i].c,e[i].k=3;
                    if(e[i].a>=e[i].b)e[i].mi=e[i].c-e[i].a,e[i].f=1;
                    else e[i].mi=e[i].c-e[i].b,e[i].f=2;
            }
        }
        if(p1<=n/2&&p2<=n/2&&p3<=n/2){cout<<sum<<endl;continue;}
        if(p1>n/2){
            sort(e+1,e+1+n,cmp);
            for(long long i=1;i<=n;i++){
                if(e[i].k!=1||p1<=n/2)break;
                sum-=e[i].mi;
                p1--;
            }
        }
        else if(p2>n/2){
            sort(e+1,e+1+n,cmp);
            for(long long i=1;i<=n;i++){
                if(e[i].k==1)continue;
                if(p2<=n/2)break;
                sum-=e[i].mi;
                p2--;
            }
        }
        else if(p3>n/2){
            sort(e+1,e+1+n,cmp);
            for(long long i=1;i<=n;i++){
                if(e[i].k<3)continue;
                if(p3<=n/2)break;
                sum-=e[i].mi;
                p3--;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}

