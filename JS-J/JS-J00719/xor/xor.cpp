#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
vector<int>a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int t=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[i].push_back(x);
        if(x==k){
            ans++;
            t=i+1;
            continue;
        }
        if(i>t){
            for(int j=0;j<a[i-1].size();j++){
                x=a[i-1][j]^a[i][0];
                if(x==k){
                    ans++;
                    t=i+1;
                    break;
                }
                a[i].push_back(x);
            }
        }

    }
    cout<<ans;
    return 0;
}
