#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500007],k=1,ans,t,kk,u1[36],u2[36],u3[36];

int c1(int x,int y){
    int l1=0,l2=0,l3=1,res=0;
    for(int i=0;i<20;++i){
        u1[i]=u2[i]=0;
    }
    while(x){
        u1[l1++]=x%2;
        x/=2;
    }
    while(y){
        u2[l2++]=y%2;
        y/=2;
    }
    for(int i=0;i<max(l1,l2);++i){
        if(u1[i]) u3[i]=1-u2[i];
        else u3[i]=u2[i];
    }

    for(int i=0;i<max(l1,l2);++i){
        res+=u3[i]*l3;
        l3*=2;
    }
    return res;
}

int c2(int x,int y){
    int l1=0,l2=0,l3=1,res=0;
    for(int i=0;i<20;++i){
        u1[i]=u2[i]=0;
    }

    //cout<<x<<" "<<y<<" sksk\n";
    while(x){
        u1[l1++]=x%2;
        x/=2;
    }
    while(y){
        u2[l2++]=y%2;
        y/=2;
    }
    //for(int i=0;i<l1;++i) cout<<u1[i]; cout<<endl;
    //for(int i=0;i<l2;++i) cout<<u2[i]; cout<<endl;
    for(int i=0;i<max(l1,l2);++i){
        if(u1[i]!=u2[i]) u3[i]=1;
        else u3[i]=0;
    }
    //for(int i=0;i<max(l1,l2);++i) cout<<u3[i]; cout<<endl;
    for(int i=0;i<max(l1,l2);++i){
        res+=u3[i]*l3;
        l3*=2;
    }
    //cout<<res<<"   dkjdkk\n";
    return res;
}


void v(int l,int r,int x,int p){
    //cout<<l<<" "<<r<<" "<<x<<" "<<p<<endl;
    //if(l==r-1 and r==n-1) cout<<"ccfctmd\n";
    if(x==kk){
        ++p;
        if(r==n-1) {
            ans=max(ans,p);
            return ;
        }else{
            v(r+1,r+1,a[r+1],p);
        }
        return ;
    }
    if(l+1<=r) v(l+1,r,c1(x,a[l]),p);
    if(r+1<n) v(l,r+1,c2(x,a[r+1]),p);
}

signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>kk;
    for(int i=0;i<n;++i) {
        cin>>a[i];
        if(a[i]!=1) k=2;
        if(a[i]!=1 and a[i]) k=3;
    }
    if(k==1 and !kk) {
        if(!kk)cout<<n/2<<endl;
        else cout<<"0\n";
        return 0;
    }
    if(k==2){
        for(int i=0;i<n;++i){
            if(kk==1 and a[i]==1)++ans;
            else if(kk==0){
                if(a[i]==0) {
                    ++ans;
                    t=0;
                }else if(a[i]==1){
                    if(t==1){
                        ++ans;
                        t=0;
                    }else{
                        t=1;
                    }
                }
            }
        }
        cout<<ans<<endl;
        return 0;
    }
    v(0,0,a[0],0);
    cout<<ans<<endl;
    return 0;
}
