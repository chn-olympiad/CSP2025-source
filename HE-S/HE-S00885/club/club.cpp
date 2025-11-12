#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,r,num,ad;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>r;
        for(int j=0;j<r;j++){
            int maxn=0;
            for(int k=0;k<=2;k++){
            cin>>num;
            if(num>maxn) maxn=num;
            }
        ad+=maxn;
        }
    }
    cout<<ad;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
