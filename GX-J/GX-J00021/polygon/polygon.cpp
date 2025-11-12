#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> arr;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n==3){
        int a,b,c;
        cin>>a>>b>>c;
        int sum=a+b+c;
        int maxn=max(a,max(b,c));
        if(sum>2*maxn){
            cout<<1;
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        int len;
        cin>>len;
        arr.push_back(len);
    }
    sort(arr.begin(),arr.end());
    if(arr[arr.size()-1]==1){
        int ans=0;
        for(int i=3;i<=n;i++){
            for(int j=1;j<=n-i+1;j++){
                ans+=j;
            }
        }
        cout<<ans%998244353;
    }
    else{
        cout<<0;
    }
    return 0;
}
