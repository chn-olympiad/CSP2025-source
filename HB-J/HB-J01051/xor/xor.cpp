#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fr(xx,aa,bb) for(xx=aa;xx<=bb;xx++)
#define rf(xx,aa,bb) for(xx=aa;xx>=bb;xx--)
const ll N=5e5;
const ll inf=0x3f3f3f3f;
const ll Inf=0x3f3f3f3f3f3f3f3f;

int n;
ll k,a[N],sm[N],ans;
ll cnt0,cnt1,cnt11,t1[N];
bool flg;

inline int qry(int l){
    ll i,j,mx=0;
    fr(i,l,n)fr(j,i,n)if((sm[i-1]^sm[j])==k){
        ll que=qry(j+1);
        mx=max(mx,que);
        // cout<<l<<' '<<i<<' '<<j<<' '<<(sm[i-1]^sm[j])<<' '<<mx<<endl;
        break;
    }
    return mx;
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ll i,j,l,m;

    cin>>n>>k;
    fr(i,1,n){
        cin>>a[i],
        sm[i]=sm[i-1]^a[i],
        flg=(flg||a[i]>1),
        cnt0+=a[i]==0,cnt1+=a[i]==1;
        if(a[i-1]==1&&a[i]==1)t1[cnt11]++;
        else if(a[i-1]==0&&a[i]==1)t1[++cnt11]++;
        
    }
    if(!flg){
        if(k==0){
            fr(i,0,cnt11)ans+=(t1[i]>>1);
            cout<<ans+cnt0;
        }
        else cout<<cnt1;
        return 0;
    }

    cout<<qry(1);

    // fprintf(stderr,"used time = %ldms\n",1000*clock()/CLOCKS_PER_SEC);
    return 0;
}
/*

*/
//g++ xor.cpp -o xor -O2 -std=c++14 -static