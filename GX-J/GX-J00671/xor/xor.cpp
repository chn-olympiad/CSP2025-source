#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;

    vector<int> a;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        a.push_back(t);
    }
    if(n==1){
        if(a[n]!=k)cout<<0;
        else cout<<1;
        return 0;
    }
    int many=0;int ans=0;
    for(int i=0;i<a.size();i++){
        for(int j=i;j<a.size();j++){
            if(i==j && i==k){
                    a[i]=0;
                    ans+=1;
            }
            else if(j-i>1){
                for(int x=i+1;x<j;x++){
                    many+=a[x];
                }
                many=many+a[i]+a[j];
                if(many==k)ans+=1;
            }
            else if(j-i==1 || i-j==1){
                    if(a[i]+a[j]==k){
                        ans+=1;
                        a[i]=0;
                        a[j]=0;
                    }
            }
        }
    }
    cout<<ans;
    return 0;
}
