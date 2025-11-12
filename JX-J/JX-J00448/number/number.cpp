#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int sum;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string n;
    cin>>n;
    for(int i=0;i<n.size();i++){
        if('0'<=n[i]&&n[i]<='9'){
            a[++sum]=n[i]-'0';
        }
    }
    sort(a+1,a+sum+1);
    for(int i=sum;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
