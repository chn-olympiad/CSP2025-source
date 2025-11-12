#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int n,k;
int a[N];
int ans;

pair<int,int>v[1000010];

bool cmp(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}

int main(){

    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>1){
            a[i]=int(a[i]^a[i-1]);
        }
    }

    int s=0;

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(int(a[j]^a[i-1])==k){
                v[++s]=(make_pair(i,j));
                break;
            }
        }
    }

    int l=0;
    sort(v+1,v+s+1,cmp);

    for(int i=1;i<=s;i++){
        if(v[i].first>l){
            ans++;
            l=v[i].second;
        }
    }

    cout<<ans;

    return 0;
}
