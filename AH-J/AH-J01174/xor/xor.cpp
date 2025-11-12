#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500010];
struct node{
    int i,j;
};
vector<node> v;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int h=a[i];
        for(int j=i;j<=n;j++){
            if(h==k){
                bool flog=0;
                for(int k=0;k<v.size();k++){
                    if(!(v[k].i>j||v[k].j<i)){
                        flog=1;
                        break;
                    }
                }
                if(flog==0){
                    ans++;
                    v.push_back({i,j});
                    cout<<i<<' '<<j<<endl;
                }
            }
            h=h^a[j];
        }
        if(h==k){
            ans++;
            v.push_back({i,n});
            cout<<i<<' '<<n<<endl;
        }
    }
    cout<<ans;
    return 0;
}

