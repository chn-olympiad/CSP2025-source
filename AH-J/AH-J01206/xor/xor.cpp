#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,k,cnt;
struct node{
    int s,t;
} a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i].s;
    }
    for(int i=1;i<=n;i++){
        a[i].t=0;
    }
    for(int i=1;i<=n;i++){
        if(a[i].s==k){
            cnt++;
            a[i].t=1;
        }
    }
    int l=1,r=n,z=0,q,flag=0;
    while(l<=r){
        for(int i=l;i<=r;i++){
            if(a[i].t==0&&z==0){
                q=a[i].s;
                z=1;
            }else if(a[i].t==0){
                q=(q^a[i].s);
            }else{
                l++;
                z=0;
                break;
            }
            if(q==k){
                flag=i;
                l=i+1;
                break;
            }
        }
        if(q!=k&&z!=0){
            l++;
            z=0;
            q=-1;
        }
        if(flag>0){
            for(int i=l;i<=flag;i++){
                a[i].t=1;
            }
            q=-1;
            flag=0;
            cnt++;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
