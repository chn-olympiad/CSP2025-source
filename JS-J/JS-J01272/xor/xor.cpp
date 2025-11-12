#include<iostream>
using namespace std;

int n,k;
bool flag=true;
int a[(int)2e5+5];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]==1)
            flag=false;
    }
    if(k==0&&flag){
        cout<<n/2<<endl;
    }else if(k<=1){
        int res=0;
        for(int i=1;i<=n;++i){
            if(a[i]==k) ++res;
            else if(k==0&&a[i]==1&&a[i+1]==1){
                ++res;
                ++i;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}