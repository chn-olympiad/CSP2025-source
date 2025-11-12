#include<bits/stdc++.h>
using namespace std;
int a[5000];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int lenth[n];
    for(int i=0;i<n;i++) scanf("%d",&lenth[i]);
    sort(lenth,lenth+n);
    if(n<3){
        cout<<"0";
        return 0;
    }else if(lenth[0]+lenth[1]+lenth[2]>lenth[2]*2){
        cout<<"1";
        return 0;
    }else{
        cout<<"0";
    }
    return 0;
}
