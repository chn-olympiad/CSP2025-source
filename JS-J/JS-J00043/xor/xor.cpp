#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    vector <int>a(n);
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    vector <int> pre(n+1,0);
    for (int i=1;i<=n;i++){
        pre[i]=pre[i-1]^a[i-1];
    }
    int num=0;
    int i=0;
    while(i<=n){
        int target=pre[i]^k;
        bool found=false;
        for (int j=i+1;j<=n;j++){
            if(pre[j]==target){
                num++;
                i=j;
                found=true;
                break;
            }

        }
        if(!found){
            i++;
        }
    }
    cout<<num;
    return 0;
}
