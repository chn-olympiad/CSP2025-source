/*
n sticks with length a[i]
need to find more than 3 sticks that can make a polygon
    their id is c[1],c[2],...,c[k]
to make a polygon, we need a[c[1]]+a[c[2]]+a[c[3]]+...+a[c[k]] >2(max a[c[]])
if the c1[] and c2[] if different, that means there's at least one c1[i] is not belongs to c2[]
find the number of how many polygons we can make, mod 998244353

sort a[] to let a[i]<=a[i+1]
then we find that the simplest situation is triangle
we find a max a[k], a min a[x], then find the smallest len a[y] to make an triangle
a[y] to a[k-1] can be the middle len
then we add more sticks
for a[1...x-1], each can be added, there's 2^(x-1)
for a[x+1...y-1], will be considered at the situation of a[x'], there's 1
for a[y+1...k-1], there's (k-1-y)
for a[k+1...n], there will be a new maxlen there's 1
then multiply all the four numbers is our number of solution of (x,k)

but if a[x] can be replaced by a[1...x-1], how to solve?
well, another nlogn
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#define INIT std::ios::sync_with_stdio(false),\
    std::cin.tie(0),std::cout.tie(0);
namespace AC{
    #define ll long long
    const int MAXN=5e3,mod=998244353;
    int n,a[MAXN+5],maxa;
    int b[MAXN+5];
    ll ans;
    int BinarySearch(int li,int ri){
        int l=li+1,r=ri-1,mid,res=-1;
        while(l<=r){
            mid=l+((r-l)>>1);
            if(a[mid]+a[li]>a[ri]) res=mid,r=mid-1;
            else l=mid+1;
        }
        return res;
    }
    int BinarySearch2(int li,int ri){
        int l=li+1,r=ri-1,mid,res=-1;
        while(l<=r){
            mid=l+((r-l)>>1);
            if(a[mid]+a[l]>=a[ri]) res=mid,r=mid-1;
            else l=mid+1;
        }
        return res;
    }
    void Init(),PreSolve(),Input(),Solve(),Answer(),ACit();
}
int main(){
    AC::ACit();
    return 0;
}
void AC::Init(){
    INIT;
    freopen("polygon.in" ,"r",stdin );
    freopen("polygon.out","w",stdout);
}
void AC::PreSolve(){
    std::sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) b[a[i]]++;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            int tmp=BinarySearch2(j,i);
            if(tmp!=-1) b[i]+=(1<<(i-tmp-1));b[i]%=mod;
        }
    }
    for(int i=1;i<=MAXN;i++) b[i]+=b[i-1];
    // for(int i=1;i<=20;i++) std::cout<<b[i]<<' '; std::cout<<'\n';
}
void AC::Input(){
    std::cin>>n;
    for(int i=1;i<=n;i++) std::cin>>a[i],maxa=std::max(maxa,a[i]);
}
void AC::Solve(){
    for(int maxi=3;maxi<=n;maxi++){
        for(int mini=1;mini<maxi;mini++){
            int midi=BinarySearch(mini,maxi);
            ll tmp=0;
            if(midi!=-1){
                tmp=(1<<(maxi-midi))-1; tmp%=mod;
                tmp*=(1<<(mini-1)); tmp%=mod;
            }
            else{
                for(int i=1;i<mini;i++){
                    
                }
            }
            ans+=tmp;ans%=mod;
        }
    }
}
void AC::Answer(){
    if(maxa==1){
        int x=2,res=1,p=n;
        while(p){
            if(p&1)res*=x;res%=mod;
            x*=x;x%=mod;
            p>>=1;
        }
        ll cnt=res%mod;
        cnt+=mod;cnt-=n;cnt-=n*(n-1)/2;cnt%=mod;
        std::cout<<cnt;
    }
    else std::cout<<(ans%mod);
}
void AC::ACit(){
    Init();
    int T=1;
    //std::cin>>T;
    while(T--){
        Input();
        PreSolve();
        Solve();
        Answer();
    }
}