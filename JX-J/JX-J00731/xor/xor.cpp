#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL k,a[10000005],n;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(k==1){
        LL num=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]==1) num++;
        }
        cout<<num;
    }else if(k==0){
        LL num=0,num1=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]==1) num++;
            else if(a[i]==0) num1++;
        }
        cout<<num/2+num1;
    }
    return 0;
}
