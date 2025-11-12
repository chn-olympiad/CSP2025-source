#include<bits/stdc++.h>
#define ffor(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define fford(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define ll long long
using namespace std;
bool st;
const int N=1e5+5;
ll t,n,cnt1,cnt2,cnt3,MAXX;ll ans,maxans;
struct mem{
    int v[3];
}mems[N];
bool ed;
void search2(int k,int cnt){
    //cout<<"-"<<k<<"-"<<cnt1<<"-"<<cnt2<<"-"<<cnt3<<"-"<<ans<<endl;
    bool flag=true;
    if(k==n) flag=false;
    ans+=mems[k].v[cnt];
    maxans=max(maxans,ans);
    if(cnt1<MAXX){
        cnt1++;if(flag)search2(k+1,0);
        cnt1--;
    }
    if(cnt2<MAXX){
        cnt2++;if(flag)search2(k+1,1);
        cnt2--;
    }
    if(cnt3<MAXX){
        cnt3++;if(flag)search2(k+1,2);
        cnt3--;
    }
    ans-=mems[k].v[cnt];
}

void solve(){
    cin>>n;
    maxans=INT_MIN;
    ans=0;
    MAXX=n/2;
    ffor(i,1,n){
        cin>>mems[i].v[0]>>mems[i].v[1]>>mems[i].v[2];
    }
    //cout<<"aa";
    cnt1++;search2(1,0);cnt1--;
    cnt2++;search2(1,1);cnt2--;
    cnt3++;search2(1,2);cnt3--;
    cout<<maxans<<endl;
}


void solve2(){
    maxans=0;ans=0;
    cin>>n;MAXX=n/2;
    ffor(i,1,n){
        cin>>mems[i].v[0]>>mems[i].v[1]>>mems[i].v[2];
    }
    ffor(i,1,n){

    }
    cout<<ans<<endl;
}

int main(){
    //cout<<(&ed-&st)/1024.0/1024.0;
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    ffor(i,1,t) solve();
    return 0;
}
