#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,a[1000]={},he=0,da=0,maxx=0;
    cin>>t;
    for(int k=1;k<=t;k++){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i];
            }
        }
    }for(int k=1;k<=t;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                if(a[i]>maxx){
                    maxx=a[i];
                }
            }
            he+=maxx;
        }
        cout<<he<<endl;
        maxx=0;
    }
        fclose(stdin);
        fclose(stdout);
    return 0;
}
