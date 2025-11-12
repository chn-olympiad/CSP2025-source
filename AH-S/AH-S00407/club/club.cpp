#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);               
    int t;
    cin>>t;
    char a[100001];
    for(int p=1;p<=t;p++){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            for(int j=1;j<=3;j++){
                int k=a[i]*j;
                if(a[i]>n/2){
                    break;
                }else{
                    cout<<k;
                }
            }
        }
    }
    return 0;
}
