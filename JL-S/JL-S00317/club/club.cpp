#include<iostream>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);


    int n,t,a1,a2,a3;

    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            for(int r=0;r<3;r++){
                cin>>a1>>a2>>a3;
            }
        }

    }
    int ans=0;
    if(a2>a1&&a2>a3) ans+=a2;
    if(a1>a2&&a1>a3) ans+=a1;
    if(a3>a2&&a3>a1) ans+=a3;

    cout<<ans;



    return 0;
}
