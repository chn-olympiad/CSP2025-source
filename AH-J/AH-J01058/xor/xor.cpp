#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5*1e5+10;
int n,k,l[N],sum[N];
/*
struct nd{
    int sum,p;
} a[N];
*/
//bool cmp(nd r,nd p){
 //   return r.sum<p.sum;
//}
struct np{
    int x,y;
};
np v[N]; int ct=0;
bool cmp2(np r,np p){
    return r.y<p.y;
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>l[i];
        sum[i]=sum[i-1]^l[i];
        //cout<<sum[i]<<" ";
        //a[i].sum=sum[i],a[i].p=i;
    }
    //cout<<endl;
    //sort(a+1,a+1+n,cmp);
    //cout<<1<<endl;
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j<i){
                cout<<0<<" ";
                continue;
            }
            int q=sum[j],p=sum[i-1];
            cout<<(p^q)<<" ";
        }
        cout<<endl;
    }
    */
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            //if(i<j)cout<<0<<" ";
            int s=0;
            int q=sum[j],p=sum[i-1];
            int y=q^p;
            if(y==k){
                v[++ct].x=i,v[ct].y=j;
            }
        }
    }
    /*
    for(int i=1;i<=ct;i++){
        cout<<v[i].x<<" "<<v[i].y<<endl;
    }
    */
    sort(v+1,v+1+ct,cmp2);
    int x1=v[1].x,yp=v[1].y,s=1;
    for(int i=1;i<=ct;i++){
        int nx=v[i].x;
        //cout<<nx<<" ";
        if(nx>yp){
            s++;
            x1=nx;
            yp=v[i].y;
        }
    }
    cout<<s<<endl;
    /*for(int i=1;i<=n;i++){
        int l=1,r=i-1;
        while(l<=r){
            int mid=l+r>>1;
            int s=a[i].sum-a[mid-1].sum;
            if(s==k){
                cout<<1
                if(a[i].p>=a[mid].p)v[++ct].x=a[mid].p,v[ct].y=a[i].p;
                l=mid+1;
            }
            if(s>k)r=mid-1;
            else l=mid+1;
        }
    }
    //cout<<1<<endl;
    sort(v+1,v+1+ct,cmp2);
    //cout<<1<<endl;
    //cout<<ct<<endl;
    for(int i=1;i<=ct;i++){
        cout<<v[i].x<<" "<<v[i].y<<endl;
    }
    int x1=v[1].x,yp=v[1].y,s=1;
    for(int i=1;i<=ct;i++){
        int nx=v[i].x;
        cout<<nx<<" ";
        if(nx>yp){
            s++;
            x1=nx;
            yp=v[i].y;
        }
    }
    cout<<s<<endl;
    */
    return 0;
}

