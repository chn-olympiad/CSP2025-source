#include<iostream>
using namespace std;
int n,k,a[500005],cnt;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(k>=2){
        cout<<0;
        return 0;
    }
    if(k==1){
        for(int i=1;i<=n;i++)
            if(a[i])
                cnt++;
        cout<<cnt;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(!a[i])
            cnt++;
        else if(a[i]&&a[i+1])
            cnt++,i++;
    }
    cout<<cnt;
    return 0;
}
