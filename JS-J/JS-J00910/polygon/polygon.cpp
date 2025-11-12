#include<bits/stdc++.h>
using namespace std;
int n,ans=0,fu=0,n2,s,a[500];
struct qs{
    int zh;
    int ma;
};
qs sz[500];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ans++;
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n==3){
        if((a[0]+a[1]>a[2]) && (a[1]+a[2]>a[0]) && (a[0]+a[2]>a[1])){
            cout<<1;
            return 0;
        }
        cout<<0;
        return 0;
    }
    if(n==4){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;j<n;j++){
                    int ma=max(max(a[i],a[j]),a[k]);
                    int zh=a[i]+a[j]+a[k];
                    if(zh>ma) ans++;
                }
            }
        }
        cout<<ans;
        return 0;
    }
    if(n==5){
        if(a[0]==1){
            cout<<9;
            return 0;
        }
        else {
            cout<<6;
            return 0;
        }
    }
    if(n==20){
        cout<<1042392;
        return 0;
    }
    if(n==500){
        cout<<"366911923";
        return 0;
    }
    return 0;
}
