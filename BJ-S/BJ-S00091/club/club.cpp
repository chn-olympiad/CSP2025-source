#include<bits/stdc++.h>
using namespace std;
int t;
struct r{
    int cnt,id,k;
};
int mid(int a,b,c){
    if(a>=b){
        if(b>=c)return b;
        else return min(a,c);
    }else{
        if(a>=c)return a;
        else return min(b,c);
    }
}bool cmp(r a,r b){
    return a.cnt>b.cnt;
}bool cmp1(r a,r b){
    return a.k>b.k;
}
void solve(){
    int n,dep,ac=0,bc=0,cc=0,sum=0;
    r mx[100100];
    cin>>n;
    dep=n/2;
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        mx[i].cnt=max(a,max(b,c));
        mx[i].id=(mx[i].cnt==a)?1:((mx[i].cnt==b)?2:3);
        if(mx[i].id==1)ac++;
        else if(mx[i].id==2)bc++;
        else cc++;
        mx[i].k=mx[i].cnt-mid(a,b,c);
    }sort(mx+1,mx+1+n,cmp);
    if(ac<=n/2&&bc<=n/2&&cc<=n/2){
        for(int i=1;i<=n;i++){
            sum+=mx[i].cnt;
        }
    }else{
        sort(mx+1,mx+1+n,cmp1);
        for(int i=1;i<=n;i++){
            if(mx[i].id==1&&ac>n/2){
                sum+=mx[i].cnt-mx[i].k;
                ac--;
            }else if(mx[i].id==2&&bc>n/2){
                sum+=mx[i].cnt-mx[i].k;
                bc--;
            }else if(mx[i].id==3&&cc>n/2){
                sum+=mx[i].cnt-mx[i].k;
                cc--;
            }else sum+=mx[i].cnt;
        }
    }cout<<sum;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
