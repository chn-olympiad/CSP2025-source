#include<bits/stdc++.h>
using namespace std;
struct member{
    long long a,b,c;
};
member a[100005];
bool cmpa(member a,member b){
    return a.a>b.a;
}
bool cmpb(member a,member b){
    return a.b>b.b;
}
bool cmpc(member a,member b){
    return a.c>b.c;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t,n,ans;
    bool f;
    cin>>t;
    for(long long i=0;i<t;i++){
        cin>>n;
        for(long long j=0;j<n;j++){
            cin>>a[j].a>>a[j].b>>a[j].c;
        }
        ans=0;
        if(n==2){
            if(a[0].a+a[1].b>ans){
                ans=a[0].a+a[1].b;
            }
            if(a[0].a+a[1].c>ans){
                ans=a[0].a+a[1].c;
            }
            if(a[0].b+a[1].a>ans){
                ans=a[0].b+a[1].a;
            }
            if(a[0].b+a[1].c>ans){
                ans=a[0].b+a[1].c;
            }
            if(a[0].c+a[1].a>ans){
                ans=a[0].c+a[1].a;
            }
            if(a[0].c+a[1].b>ans){
                ans=a[0].c+a[1].b;
            }
            cout<<ans<<endl;
            continue;
        }
        f=false;
        for(int j=0;j<4;j++){
            if(a[j].b!=0||a[j].c!=0){
                f=true;
                break;
            }
            if(f==true){
                break;
            }
        }
        if(f==false){
            sort(a,a+n,cmpa);
            for(int j=0;j<n/2;j++){
                ans+=a[j].a;
            }
            cout<<ans<<endl;
            continue;
        }
        f=false;
        for(int j=0;j<4;j++){
            if(a[j].a!=0||a[j].c!=0){
                f=true;
                break;
            }
            if(f==true){
                break;
            }
        }
        if(f==false){
            sort(a,a+n,cmpb);
            for(int j=0;j<n/2;j++){
                ans+=a[j].b;
            }
            cout<<ans<<endl;
            continue;
        }
        f=false;
        for(int j=0;j<4;j++){
            if(a[j].a!=0||a[j].b!=0){
                f=true;
                break;
            }
            if(f==true){
                break;
            }
        }
        if(f==false){
            sort(a,a+n,cmpc);
            for(int j=0;j<n/2;j++){
                ans+=a[j].c;
            }
            cout<<ans<<endl;
            continue;
        }
        for(int j=0;j<n;j++){
            if(a[j].a>a[j].b&&a[j].a>a[j].c){
                ans+=a[j].a;
            }
            else if(a[j].b>a[j].a&&a[j].b>a[j].c){
                ans+=a[j].b;
            }
            else if(a[j].c>a[j].a&&a[j].c>a[j].b){
                ans+=a[j].c;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
