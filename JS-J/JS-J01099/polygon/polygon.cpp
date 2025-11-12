#include<bits/stdc++.h>
using namespace std;
#define ll long long;
#define pii pair<int,int>
#define st(s) sort(s.begin(),s.end())
#define pb(n) push_back(n)
#define rv(s) reverse(s.begin(),s.end())
#define ins(n) insert(n)
#define vt vector
#define endl "\n"
int mi(int n){
    if(n==0) return 1;
    return (mi(n-1)*2)%998244353;
}
int lng[5050];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,maxn,sum,res=0;
    unsigned long long aa;
    cin>>n;
    if(n>63){
        cout<<mi(n)-1-n-n*(n-1)/2;
        return 0;
    }
    for(int i=0;i<n;i++){
        cin>>lng[i];
    }
    for(aa=0;aa<(mi(n));aa++){
        maxn=sum=0;
        for(int j=0;j<n;j++){
            if((aa>>j)&1){
                sum+=lng[j];
                maxn=max(maxn,lng[j]);
            }
        }
        if(sum>(2*maxn)){
            res++;
            if(res>=998244353){
                res-=998244353;
            }
        }
    }
    cout<<res;
    return 0;
}
//64 points
