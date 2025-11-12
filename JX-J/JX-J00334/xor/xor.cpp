#include<iostream>
#include<vector>

using namespace std;
int a[100010],n,b,k,ans;
vector<int> ns;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(j==i){
                b=a[i];
                ns.push_back(a[i]);
            }
            else{
                b=b^a[j];
                ns.push_back(b);
            }
        }
    }
    for(int i=0;i<ns.size();i++){
        if(ns[i]==k){
            ans+=1;
        }
    }
    cout<<ans;
    return 0;
}
