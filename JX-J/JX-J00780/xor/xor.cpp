#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],b[500005];
/*
struct node{
    int l,r,m;
};
vector<node>c;
bool check(){
    for(int i=0;i<c.size();i++){
        if(c[i].m>0) return 0;
    }
    return 1;
}
bool cmp(node x,node y){
return x.m>y.m;}
*/
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>=2) b[i]=a[i]^b[i-1];
        else b[i]=a[i];
    }
    int cnt=0;
    for(int l=1;l<=n;l++){
        for(int r=l;r<=n;r++){
            int x=b[r]^b[l-1];
            if(l==r) x=a[l];
            if(l==1) x=b[r];
            if(x==k){
                //node t;
                //t.l=l;t.r=r;
                //c.push_back(t);
                cnt++;
                //cout<<l<<" "<<r<<endl;
            }
        }
    }
    /*
    do{
        for(int i=0;i<c.size()-1;i++){
            for(int j=i+1;j<c.size();j++){
                if(c[j].l==c[i].l&&c[j].r==c[i].r) continue;
                if(c[j].l<=c[i].l||c[i].l<=c[j].r||c[j].r<=c[i].r){
                    c[i].m++;
                    c[j].m++;
                }
            }
        }
        sort(c.begin(),c.end(),cmp);
        c.erase(c.begin(),c.begin()+1);
    }while(!check());
    */
    cout<<cnt<<endl;
    return 0;
}
