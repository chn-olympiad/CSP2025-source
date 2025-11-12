#include<bits/stdc++.h>
using namespace std;
int n,cnt=INT_MIN;
bool ab=1;
struct node{
    int a,b,c;
    void input(){
        cin>>a>>b>>c;
        if(b!=0)ab=0;
    }
}a[100005];
bool cmp(node x,node y){
    return x.a>y.a;
}
bool cmp2(node x,node y){
    return x.b>y.b;
}
void func(int i,int ai,int b,int c,int ans2){
    if(i==n+1){
        cnt=max(cnt,ans2);
        return;
    }
    if(ai)func(i+1,ai-1,b,c,ans2+a[i].a);
    if(b)func(i+1,ai,b-1,c,ans2+a[i].b);
    if(c)func(i+1,ai,b,c-1,ans2+a[i].c);
}
void func2(int i,int ai,int b,int ans2){
    if(i==n+1){
        cnt=max(cnt,ans2);
        return;
    }
    if(ai)func2(i+1,ai-1,b,ans2+a[i].a);
    if(b)func2(i+1,ai,b-1,ans2+a[i].b);
}
void _main(){
    cnt=INT_MIN;
    cin>>n;
    for(int i=1;i<=n;i++)a[i].input();
    if(n<=30){
        func(1,n/2,n/2,n/2,0);
        cout<<cnt<<endl;
    }else if(ab){
        sort(a+1,a+1+n,cmp);
        long long ans=0;
        for(int i=1;i<=n/2;i++)ans+=a[i].a;
        cout<<ans<<endl;
    }else{
        func2(1,n/2,n/2,0);
        cout<<cnt;
    }
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)_main();
    return 0;
}
