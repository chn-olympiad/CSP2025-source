#include<bits/stdc++.h>
using namespace std;
struct manyi{
        int one;
        int two;
        int three;
        //int maxx;
        //int di;
    };
bool comp1(manyi aaa,manyi bbb){
    return aaa.one>bbb.one;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int iii=0;iii<t;iii++){
        manyi a[100000];
        int n,u,p[4]={};
        long long ans=0;
        bool erer=1,sansan=1;
        cin>>n;
        for(int i=0;i<n;i++){
            int linn=-1;
            cin>>a[i].one;
            cin>>a[i].two;
            if(a[i].two){
                erer=0;
            }
            cin>>a[i].three;
            if(a[i].three){
                sansan=0;
            }
        }
        if(erer&&sansan){
            sort(a,a+n,comp1);
            for(int i=0;i<n/2;i++){
                ans+=a[i].one;
            }
            cout<<ans<<endl;
        }else if(sansan){
            cout<<ans<<endl;
        }else{
cout<<ans<<endl;
}


    }
    return 0;
}
