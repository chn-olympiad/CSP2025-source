#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r,a[122];
    cin>>n>>m;
    for(int i=0;i<n*m;++i){
        cin>>a[i];
    }
    r=a[0];
    sort(a,a+n*m,cmp);
    int ni=0,i=1,j=1;
    while(a[ni]!=r){
        if(j%2==1){
            if(i<n){
                ++i;
            }else{
                ++j;
            }
        }else{
            if(i>1){
                --i;
            }else{
                ++j;
            }
        }
        ++ni;
    }
    cout<<j<<" "<<i;
    return 0;
}
