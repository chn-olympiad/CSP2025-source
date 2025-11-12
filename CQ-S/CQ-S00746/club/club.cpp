#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long t,n,myd[N],bm[N],sum;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>n;
        while(n--){
            for(int i=1;i<=3;i++){
                cin>>myd[i];
            }
        }
                   sum=0;
            for(int i=1;i<=3;i++){
                if(bm[i]<=n/2){
                    sum+=max(sum,myd[i]);
                    bm[i]++;
                }
                }
            cout<<sum<<endl;
    }
    return 0;
}
