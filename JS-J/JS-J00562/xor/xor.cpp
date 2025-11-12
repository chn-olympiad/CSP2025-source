#include<bits/stdc++.h>
using namespace std;
int n,m,k;
pair<int,int> v[1005005];
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.second!=b.second) return a.second<b.second;
    else return a.first<b.first;
}
const int N=5e5+5;
int a[N],qzh[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int dk=0;
    for(int i=1;i<=n;i=-~i){
        cin>>a[i];
        if(a[i]==1) dk++;
        qzh[i]=(qzh[i-1]^a[i]);
    }
    if(n<=1009){
        int pos=0;
        for(int l=1;l<=n;l=-~l){
            for(int r=l;r<=n;r=-~r){
                int sum=(qzh[r]^qzh[l-1]);
                if(sum==k) v[++pos]=make_pair(l,r);
            }
        }
        sort(v+1,v+pos+1,cmp);
        int nwlf=0,ans=0;
        for(int i=1;i<=pos;i++){
            if(v[i].first>nwlf){
                ans++;
                nwlf=v[i].second;
            }
        }
        cout<<ans;
    }
    else{
        cout<<dk<<endl;
    }
}
