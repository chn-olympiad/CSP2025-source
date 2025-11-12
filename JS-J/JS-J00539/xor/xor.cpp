//50
#include <bits/stdc++.h>
using namespace std;

vector<int> a;
bool used[500000];
/*
int value(const vector<int> &a){
    int l=a.size();
    int ans=a[0];
    for(int i=1;i<=l;i++){
        ans^=a[i];
    }
    return ans;
}
*/

inline bool can_try(int l,int r){
    for(int i=l;i<=r;i++){
        if(used[i]){
            return false;
        }
    }
    return true;
}

inline bool right(int l,int r,int k){
    int ans=a[l];
    for(int i=l+1;i<=r;i++){
        ans^=a[i];
    }
    if(ans==k){
        //cout<<"ffuck"<<l<<r<<ans<<k;
        return true;
    }
    return false;
}

int main(){

    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,k;
    int ans=0;
    cin>>n>>k;
    a.push_back(0);
    for(int i=1;i<=n;i++){
        int ai;
        cin>>ai;
        a.push_back(ai);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            if(can_try(j,j+i-1)){
                //cout<<i<<j<<'\n';
                if(right(j,j+i-1,k)){
                    ans++;
                    //cout<<"fuck";
                    for(int ii=j;ii<=j+i-1;ii++){
                        used[ii]=true;
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}

