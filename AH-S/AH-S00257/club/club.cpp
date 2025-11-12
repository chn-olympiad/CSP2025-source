#include<bits/stdc++.h>
using namespace std;
struct Node{
    int a,b,c;
}a[100005];
int t,n;
bool comp1(Node x,Node y){
    return x.a>y.a;
}
bool comp2(Node x,Node y){
    return x.c<y.c;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        long long ans=0;
        bool flag=true;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
            if(flag&&a[i].b!=0){
                flag=false;
            }
        }
        if(n==2){
            int minx=a[1].a,maxx=a[1].a,miny=a[2].a,maxy=a[2].a;
            minx=min(minx,a[1].b),maxx=max(maxx,a[1].b),miny=min(miny,a[2].b),maxy=max(maxy,a[1].b);
            minx=min(minx,a[1].c),maxx=max(maxx,a[1].c),miny=min(miny,a[2].c),maxy=max(maxy,a[1].c);
            if(maxx!=maxy){
                cout<<maxx+maxy<<'\n';
            }else{
                cout<<(a[1].a+a[1].b+a[1].c-maxx-minx>a[2].a+a[2].b+a[2].c-maxy-miny?a[1].a+a[1].b+a[1].c-maxx-minx+maxy:a[2].a+a[2].b+a[2].c-maxy-miny+maxx)<<'\n';
            }
            continue;
        }
        if(flag){
            sort(a+1,a+1+n,comp1);
            for(int i=1;i<=n/2;i++){
                ans+=a[i].a;
            }
        }else{
            for(int i=1;i<=n;i++){
                a[i].c=a[i].a-a[i].b;
            }
            sort(a+1,a+1+n,comp2);
            for(int i=1;i<=n/2;i++){
                ans+=a[i].a;
            }
            for(int i=n;i>n/2;i--){
                ans+=a[i].b;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
