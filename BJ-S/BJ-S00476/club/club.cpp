#include<bits/stdc++.h>
using namespace std;
int t;
int n;
const int N=1e5;
struct S{
    int a,b,c;
}a[N];
bool cmpA(S a,S b){
    return a.a>b.a;
}
void tA(){
    int ans=0;
    sort(a+1,a+n+1,cmpA);
    int k=0;
    for(int i=1;i<=n;i++){
        ans+=a[i].a;
        k++;
        if(k==n/2){
            break;
        }
    }
    cout<<ans<<endl;
}
bool cmpB(S a,S b){
    return abs(a.a-a.b)>abs(b.a-b.b);
}
void tB(){
    bool f=false;
    sort(a+1,a+n+1,cmpB);
    if(a[1].a>a[1].b){
        f=true;
    }
    int ans=0;
    for(int i=1;i<=n/2;i++){
        ans+=(f?a[i].a:a[i].b);
    }
    for(int i=n/2+1;i<=n;i++){
        ans+=(f?a[i].b:a[i].a);
    }
    cout<<ans<<endl;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        bool A=false,B=false;
        for(int i=1;i<=n;i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
            if(a[i].b!=0||a[i].c!=0){
                A=true;
            }
            if(a[i].c!=0){
                B=true;
            }
        }
        if(!A){
            tA();
            continue;
        }
        if(!B){
            tB();
            continue;
        }
        if(n==2){
            int x=a[1].a,y=a[1].b,z=a[1].c;
            int u=a[2].a,v=a[2].b,w=a[2].c;
            cout<<max(x+v,max(x+w,max(y+u,max(y+w,max(z+u,z+v)))))<<endl;
            continue;
        }
    }
    return 0;
}
