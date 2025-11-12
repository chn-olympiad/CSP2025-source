#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
int n,k;
int a[N];
int ans;
struct node{
    int l,r;
};
bool b[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    bool f=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1&&a[i]!=0){
            f=0;
        }
    }
    if(f){
        if(k){
            for(int i=1;i<=n;i++){
                if(a[i]){
                    ans++;
                }
            }
        }else{
            for(int i=1;i<=n;i++){
                if(!a[i]){
                    ans++;
                }else if(i<n&&a[i+1]){
                    ans++;
                }
            }
        }
        cout<<ans;
        return 0;
    }
    vector<node>v;
    for(int i=1;i<=n;i++){
        for(int l=1;l<=n-i+1;l++){
            int r=l+i-1;
            int x=0;
            for(int j=l;j<=r;j++){
                x=x^a[j];
            }
            if(x==k){
                v.push_back({l,r});
            }
        }
    }
    for(auto i:v){
        bool f=1;
        for(int j=i.l;j<=i.r;j++){
            if(b[j]){
                f=0;
                break;
            }
        }
        if(f){
            ans++;
            for(int j=i.l;j<=i.r;j++){
                b[j]=1;
            }
        }
    }
    cout<<ans;
    return 0;
}

