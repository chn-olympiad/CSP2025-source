#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    vector<int>v;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int sun=0,c=n;
    for(int i=0;i<n;i++){
        int sum;
        while(c-1>=0){
            sum=v[i]^v[i+1];
            c--;
            i++;
        }
        if(sum==k){
            sun=max(sun,sum);
        }
        else{
            c--;
        }
    }
    cout<<sun;

    return 0;
}
