#include<bits/stdc++.h>
using namespace std;
struct student{
    int x,y,z,lowmaxa,maxa,pos;
};
int t;
bool cmp1(student x,student y){return x.maxa>y.maxa;}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int n,ans=0,l=0,f[100005],b[100005];
        student a[100005];
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z,a[i].maxa=max(a[i].x,max(a[i].y,a[i].z)),b[i]=0x7fffffff;
            if(a[i].maxa==a[i].x)a[i].pos=1,a[i].lowmaxa=max(a[i].y,a[i].z);
            else if(a[i].maxa==a[i].y)a[i].pos=2,a[i].lowmaxa=max(a[i].x,a[i].z);
            else a[i].pos=3,a[i].lowmaxa=max(a[i].y,a[i].x);
        }
        for(int i=1;i<=n;i++)b[i]=min(b[i],a[i].maxa-a[i-1].lowmaxa);
        sort(a+1,a+n+1,cmp1);
        for(int i=1,n1=0,n2=0,n3=0;i<=n;i++){
            if(a[i].pos==1){
                if(n1+1<=n/2)f[i]=f[i-1]+a[i].maxa,n1++;
                else f[i]=max(f[i-1]+a[i].lowmaxa,f[i-1]+a[i].maxa-b[i-1]);
            }
            if(a[i].pos==2){
                if(n2+1<=n/2)f[i]=f[i-1]+a[i].maxa,n2++;
                else f[i]=max(f[i-1]+a[i].lowmaxa,f[i-1]+a[i].maxa-b[i-1]);
            }
            if(a[i].pos==3){
                if(n3+1<=n/2)f[i]=f[i-1]+a[i].maxa,n3++;
                else f[i]=max(f[i-1]+a[i].lowmaxa,f[i-1]+a[i].maxa-b[i-1]);
            }
        }
        cout<<f[n]<<'\n';
    }
    return 0;
}
