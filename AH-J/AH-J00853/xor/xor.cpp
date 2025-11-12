#include<bits/stdc++.h>;
using namespace std;
int a[50005];
int cnt=0;
int  main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            cnt++;
        }
    }
    if(cnt==n&&n<=2){
        cout<<1;
    }
    if(n<=10){
            if(k==0){
                cnt=0;
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=n;j++){
                        if(a[i]^a[j]==0&&i!=j){
                            cnt++;
                        }
                    }
                }
                cout<<cnt;
            }else if(k==1){
                cnt=0;
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=n;j++){
                        if(a[i]^a[j]==1&&i!=j){
                            cnt++;
                        }
                    }
                }
                cout<<cnt;
            }
    }
    return 0;
}
