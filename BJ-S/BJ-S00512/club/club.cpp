#include<bits/stdc++.h>
using namespace std;
struct me{
    int n,m,k;
    bool xv;
}a[100001];
bool cmp(me a,me b){
    if(!a.xv) return a.n>b.n;
}
bool cmp1(me a,me b){
    if(!a.xv) return a.m>b.m;
}
bool cmp2(me a,me b){
    if(!a.xv) return a.k>b.k;
}
int a1,a2,a3;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,s;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>s;
        for(int j=1;j<=s;j++){
                cin>>a[j].n>>a[j].m>>a[j].k;
                a[j].xv=false;
        }
                sort(a+1,a+s+1,cmp);
                a[1].xv=true;
                a[2].xv=true;
                a1=a[1].n+a[2].n;
                sort(a+1,a+s+1,cmp1);
                a[1].xv=true;
                a[2].xv=true;
                a2=a[1].m+a[2].m;
                sort(a+1,a+s+1,cmp2);
                a[1].xv=true;
                a[2].xv=true;
                a3=a[1].k+a[2].k;
            if(a1+a2>a1+a3&&a1+a2>a2+a3) cout<<a1+a2<<endl;
            else if(a1+a3>a1+a2&&a1+a3>a2+a3) cout<<a1+a3<<endl;
            else if(a3+a2>a1+a3&&a2+a2>a2+a1) cout<<a2+a3<<endl;
    }
    return 0;
}
