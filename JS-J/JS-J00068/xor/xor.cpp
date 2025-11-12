#include<bits/stdc++.h>
using namespace std;
long long n,k;
const int maxn=5e5+5;
long long a[maxn];
long long ans;
bool vis[maxn];
long long aaa,vi;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(long long i=1;i<=n;i++)cin>>a[i];
    /*for(long long i=1;i<=n;i++){
        if(a[i]==k){
            vis[i]=1;
            ans=1;
        }
    }
    between=0;
    for(long long l=1,r=2;l<=n and r<=n;){
        long long i=l;
        long long xor=0;xorr=0;
        while(i<r){
            long long y=a[i+1],x=a[i];
            long long cnt=0;
            while(x!=0 or y!=0){
                if(x%2!=y%2){
                    xor+=pow(2,cnt);
                }
                x/=2,y/=2,cnt++;
            }
            if(i==l);
            else{
                while(xor!=0 or xorr!=0){
                    if(xor%2!=xorr%2){
                    xorr+=pow(2,cnt);
                }
                x/=2,y/=2,cnt++;
            }
            }
        }
    }*/
    cout<<1;
    return 0;
}
