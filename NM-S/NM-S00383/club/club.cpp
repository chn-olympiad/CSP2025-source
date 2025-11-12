#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int t,n;
struct Node{
    int a1,a2,a3;
}p[N];
bool cmp1(Node a,Node b){
    return a.a1>b.a1;
}
bool cmp2(Node a,Node b){
    return a.a2>b.a2;
}
bool cmp3(Node a,Node b){
    return a.a3>b.a3;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        memset(p,0,sizeof p);
        long long ans1=0,ans2=0,ans3=0,ans,f1=0,f2=0,f3=0,f;
        for(int i=1;i<=n;i++) cin>>p[i].a1>>p[i].a2>>p[i].a3;
        sort(p+1,p+1+n,cmp1);
        for(int i=1;i<=n/2;i++) ans1+=p[i].a1,f1+=p[n-i+1].a1;
        sort(p+1,p+1+n,cmp2);
        for(int i=1;i<=n/2;i++) ans2+=p[i].a2,f2+=p[n-i+1].a2;
        sort(p+1,p+1+n,cmp3);
        for(int i=1;i<=n/2;i++) ans3+=p[i].a3,f3+=p[n-i+1].a3;
        ans=max(ans1,max(ans2,ans3));
        if(ans==ans1){
            for(int i=1;i<=n/2;i++) ans=max(ans,max(ans-p[i].a1+p[i].a2,ans-p[i].a1+p[i].a3));
            f=max(f2,f3);
            if(f==f2) for(int i=n/2+1;i<=n;i++) f=max(f,f-p[i].a2+p[i].a3);
            else for(int i=n/2+1;i<=n;i++) f=max(f,f-p[i].a3+p[i].a2);
        }
        else if(ans==ans2){
            for(int i=1;i<=n/2;i++) ans=max(ans,max(ans-p[i].a2+p[i].a1,ans-p[i].a2+p[i].a3));
            f=max(f1,f3);
            if(f==f1) for(int i=n/2+1;i<=n;i++) f=max(f,f-p[i].a1+p[i].a3);
            else for(int i=n/2+1;i<=n;i++) f=max(f,f-p[i].a3+p[i].a1);
        }
        else if(ans==ans3){
            for(int i=1;i<=n/2;i++) ans=max(ans,max(ans-p[i].a3+p[i].a1,ans-p[i].a3+p[i].a2));
            f=max(f2,f1);
            if(f==f2) for(int i=n/2+1;i<=n;i++) f=max(f,f-p[i].a2+p[i].a1);
            else for(int i=n/2+1;i<=n;i++) f=max(f,f-p[i].a1+p[i].a2);
        }
        cout<<ans+f<<endl;
    }
    return 0;
}
