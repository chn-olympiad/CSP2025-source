#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int t,n,k=0;
int a[N][4];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                while(n--){
                    for(int i=n;i>=0;i--){
                        if(i==n){
                            k=max(k,j);
                            k++;
                    }
                }
            }
        }
        cout<<k<<endl;
    }
    return 0;
}