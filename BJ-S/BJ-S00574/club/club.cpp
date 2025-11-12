#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    int a[n][3];
    int c[n];
    cin>>t;
    for(int i=1;i<=t;i++){
        int sum=0;
        for(int i=1;i<=3;i++) c[i]=0;
        int best;
        cin>>n;
        for(int j=1;j<=n;j++){
            int tmp=0;
            for(int k=1;k<=3;k++){
                cin>>a[j][k];
                if(a[j][k]>tmp){
                    tmp=a[j][k];
                    best=k;
                }
            }
            for(int k=1;k<=3;k++){
                if(best==k) c[best]+=1;
            }
            sum+=tmp;
        }
        cout<<sum<<endl;
    }
    return 0;
    }