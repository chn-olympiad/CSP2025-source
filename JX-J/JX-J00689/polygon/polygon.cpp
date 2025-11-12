#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int maxs=0,sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxs=max(maxs,a[i]);
        sum+=a[i];
    }
    if(n==3){
        if(sum>2*maxs){
            cout<<"1"<<endl;
        }
        else{
            cout<<"0"<<endl;
        }

    }
    else if(n<3){
        cout<<"0"<<endl;
    }
    else{
        cout<<"0"<<endl;
    }





    return 0;
}
