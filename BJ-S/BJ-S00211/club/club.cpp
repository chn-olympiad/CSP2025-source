#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull ;
const int N=1e5+9;
struct node{
    ull x,y,z;
}s[N];
bool cmp(node a,node b){return a.x>b.x;}
bool cmp1(node a,node b){
    if(a.x!=b.x) return a.x>b.x;
    else return a.y>b.y;
}
void xxx(){
    ull n,cnta=0,cntb=0,cntc=0,cntx=0,cnty=0,cntz=0;
    cin>>n;
    ull n2=n/2;
    for(int i=1;i<=n;i++) cin>>s[i].x>>s[i].y>>s[i].z;
    if(s[1].y==0&&s[1].z==0){
        ull cnt=0;
        sort(s+1,s+n+1,cmp);
        for(int i=1;i<=n2;i++) cnt+=s[i].x;
        cout<<cnt<<endl;
        return;
    }else if(s[1].z==0){
        ull cnt1=0,cnt2=0;
        sort(s+1,s+n+1,cmp1);
        //for(int i=1;i<=n;i++) cout<<s[i].x<<" "<<s[i].y<<" "<<s[i].z<<" "<<endl;
        for(int i=1;i<=n2;i++) cnt1+=s[i].x;
        for(int i=n2+1;i<=n;i++) cnt2+=s[i].y;
        cout<<cnt1+cnt2<<endl;
        return;
    }else if(n==2){
        ull mx=max({s[1].x,s[1].y,s[1].z});
        if(cntx<=n2){
            cntx++;
            cnta+=mx;
        }
        if(cnty<=n2){
            cnty++;
            cntb+=mx;
        }
        if(cntz<=n2){
            cntz++;
            cntc+=mx;
        }
        if(cntx==1){
            ull mx1=max(s[2].y,s[2].z);
            if(mx1==cnty) cntb+=mx;
            if(mx1==cntz) cntc+=mx;
            if(cntb) cout<<cnta+cntb<<endl;
            else cout<<cnta+cntc<<endl;
        }
        if(cnty==1){
            ull mx1=max(s[2].x,s[2].z);
            if(mx1==cntx) cnta+=mx;
            if(mx1==cntz) cntc+=mx;
            if(cnta) cout<<cnta+cntb<<endl;
            else cout<<cntb+cntc<<endl;
        }
        if(cntz==1){
            ull mx1=max(s[2].y,s[2].x);
            if(mx1==cnty) cntb+=mx;
            if(mx1==cntx) cnta+=mx;
            if(cntb) cout<<cntc+cntb<<endl;
            else cout<<cnta+cntc<<endl;
        }
        return;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ull t;
    cin>>t;
    while(t--) xxx();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
