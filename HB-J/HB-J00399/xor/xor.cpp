#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int s[10];
int sum;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[a[i]]++;
    }
    if(k==1){
        cout<<s[1]<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==0)sum++;
        else if(a[i]==a[i+1]){
            sum++;i++;
        }
    }
    cout<<sum<<endl;
    return 0;
}
