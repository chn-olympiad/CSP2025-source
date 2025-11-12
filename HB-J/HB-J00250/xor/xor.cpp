#include<bits/stdc++.h>
using namespace std;
long long n,k,a[100005],s;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1) s++;
    }
    if(k==1) cout<<s;
    else{
        int sum=0,t=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                sum++;
                t=0;
            }
            else{
                if(t){
                    sum++;
                    t=0;
                }else t=1;
            }
        }
        cout<<sum;
    }
    return 0;
}
