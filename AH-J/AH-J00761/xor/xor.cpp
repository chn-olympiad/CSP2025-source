#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,t;
int a[500005];
struct node{
    int st,ed;
}m[500005];
bool cmp(node l,node r){
    if(l.ed!=r.ed){
        return l.ed<r.ed;
    }
    return l.st>r.st;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l;
    for(int i=1;i<=n;i++){
        l=a[i];
        if(l==k){
            t++;
            m[t].st=i;
            m[t].ed=i;
        }
        for(int j=i+1;j<=n;j++){
            l=(l|a[j])-(l&a[j]);
            if(l==k){
                t++;
                m[t].st=i;
                m[t].ed=j;
            }
        }
    }
    sort(m+1,m+1+t,cmp);
    int ed_=0,cnt=0;
    for(int i=1;i<=t;i++){
        if(ed_<m[i].st){
            cnt++;
            ed_=m[i].ed;
        }
    }
    cout<<cnt;
    return 0;
}
