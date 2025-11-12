#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,TOT=0,a[500005],sum1[500005];
struct node{
    int l,r;
}sum2[500005],c[500005];
bool cmp(node s1,node s2){return s1.l<s2.l;}
bool cmp2(node s1,node s2){
    return(s1.l==s2.l?s1.r<s2.r:s1.l<s2.l);
}
int Lower__(int t){
    int l=0,r=n+1;
    while(l+1<r){
        int mid = (r-l)/2+l;
        if(sum2[mid].l>=t) r = mid;
        else l = mid;
    }
    return r;
}
int Upper__(int t){
    int l=0,r=n+1;
    while(l+1<r){
        int mid = (r-l)/2+l;
        if(sum2[mid].l>t) r = mid;
        else l = mid;
    }
    return r;
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum1[i]=sum1[i-1]^a[i];
        sum2[i].l=sum1[i]^k;
        sum2[i].r=i;
    }
    sum2[n+1].r = 1e9;
    sort(sum2+1,sum2+n+1,cmp);
    for(int i=1;i<=n;i++){
        int pointl = Lower__(sum1[i]);
        int pointr = Upper__(sum1[i]);
        if(pointl==pointr) continue;
        int PO1=-1,PO2=n+5;
        for(int j=pointl;j<pointr;j++){
            if(sum2[j].r>i) PO2=min(PO2,sum2[j].r);
            else PO1 = max(PO1,sum2[j].r);
        }
        if(PO1!=-1&&min(PO1,i)+1<=max(PO1,i)){
            ++TOT;
            c[TOT].l = min(PO1,i)+1;
            c[TOT].r = max(PO1,i);
        }
        if(PO2!=n+5&&min(PO2,i)+1<=max(PO2,i)){
            ++TOT;
            c[TOT].l = min(PO2,i)+1;
            c[TOT].r = max(PO2,i);
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]==k){
            TOT++;
            c[TOT].l = c[TOT].r = i;
        }
        if(sum1[i]==k){
            TOT++;
            c[TOT].l = 1,c[TOT].r = i;
        }
    }
    sort(c+1,c+TOT+1,cmp2);
    int to=0;
    for(int i=1;i<=TOT;i++){
        if(c[i].l!=c[i-1].l&&c[i].l<=c[i].r) c[++to] = c[i];
    }
    TOT = to;
    int P=-1,point=1,cnt=0;
    for(int i=1;i<=n;i++){
        if(i==c[point].l){
            if(c[point].r<P) P = c[point].r;
            else if(i>P){
                cnt++;
                P = c[point].r;
            }
            point++;
        }
    }
    cout<<cnt;
    return 0;
}