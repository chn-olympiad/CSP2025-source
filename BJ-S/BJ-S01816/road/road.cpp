
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long n=0,m=0,k=0,a=0,ans=0;
long long aaa[100000][5];
long long aa[100000]={},ab[100000]={};
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i!=m;i++){
        cin>>aaa[i][0]>>aaa[i][1]>>aaa[i][2];
        aa[aaa[i][2]]++;
        a=max(a,aaa[i][2]);
    }
    int b=0;
    for(int i=0;i!=a+1;i++){
        if(b>=n-1){
            break;
        }
        b+=aa[i];
        ans+=aa[i]*i;
    }
    cout<<ans;
    return 0;
}