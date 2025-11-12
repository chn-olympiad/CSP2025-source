#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500010;
int n,k;
bool v[N];
int a[N];
int cnt;
int xo(int x,int y){
    int ans=0;
    string s1="";
    string s2="";
    int k1=0,k2=0;
    while(x!=0){
        char c=x%2+'0';
        s1=s1+c;
        x/=2;
        k1++;
    }
    while(y!=0){
        char c=y%2+'0';
        s2=s2+c;
        y/=2;
        k2++;
    }
    if(k1<k2){
        while(k1!=k2){
            s1=s1+'0';
            k1++;
        }
    }else if(k1>k2){
        while(k1!=k2){
            s2=s2+'0';
            k2++;
        }
    }
    for(int i=k1-1;i>=0;i--){
        if(s1[i]!=s2[i]){
            ans=ans*2+1;
        }else{
            ans=ans*2;
        }
    }
    return ans;
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k){
            cnt++;
            v[i]=1;
        }
    }
    for(int l=1;l<=n;l++){
        if(v[l]==0){
            int x=a[l];
            for(int r=l+1;r<=n;r++){
                if(v[r]==0){
                    x=xo(x,a[r]);
                    if(x==k){
                        cnt++;
                        for(int i=l;i<=r;i++)v[i]=1;
                        l=r+1;
                    }
                }else{
                    x=0;
                    break;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
