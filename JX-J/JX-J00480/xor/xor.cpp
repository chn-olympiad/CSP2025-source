#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],s[N],idx,ans=1;
map<int,int> mp,mm;
struct no{
    int l,r;
}e[N];
bool cmp(no x,no y){
    return x.r<y.r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    int ff=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]^a[i];
        mp[a[i]]++;
        if(a[i]!=0 && a[i]!=1)ff=0;
    }
    if(ff){
        if(k!=0 && k!=1){
            cout<<0;
            return 0;
        }
        if(mp[0]==n){
            if(k==0)cout<<mp[0];
            if(k==1)cout<<0;
            return 0;
        }
        if(mp[1]==n){
            if(k==0)cout<<mp[1]/2;
            else cout<<mp[1];
            return 0;
        }
        if(k==0){
            cout<<mp[0]+mp[1]/2;
            return 0;
        }
        if(k==1){
            cout<<mp[1];
            return 0;
        }
        ans=0;
        int i=1;
        while(i<=n){
            while(a[i]==a[i+1]&&i<=n)ans++,i++;
            i++,ans++;
            if(a[i]!=a[i+1])ans++,i+=2;
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(i==1){
                if(s[j]==k){
                    e[++idx]={i,j};
                }
            }
            else if(i==j){
                if(a[i]==k)e[++idx]={i,j};
            }
            else if((s[j]^s[i-1])==k){
                e[++idx]={i,j};
            }
        }
    }
    sort(e+1,e+idx+1,cmp);
    int f=1;
    for(int i=2;i<=idx;i++){
        if(f==1){
            if(e[i].l>e[i-1].r)ans++,f=1;
            else f=0;
        }
        else{
            if(e[i].l>e[i-2].r)ans++,f=1;
            else f=0;
        }
    }
    cout<<ans;
    return 0;
}