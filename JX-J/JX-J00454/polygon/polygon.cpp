#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int x,num=0,sum=0;
void js(int wei,int zong,int ma,int liang){
    if(liang>=3){
        sum++;
        cout<<wei<<endl;
    }
    if(liang>=3&&zong>2*ma){
        num++;
    }
    if(wei<=x){
        js(wei+1,zong,ma,liang);
        js(wei+1,zong+a[wei],max(ma,a[wei]),liang+1);
    }
    return 0;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>x;
    if(x<3){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=x;i++){
        cin>>a[i];
    }
    js(1,0,0,0);
    cout<<num<<" "<<sum;
}
