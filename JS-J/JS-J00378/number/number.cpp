#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int b[1000];
    long long cnt=0,ans=0;
    cin>>a;
    //cout<<a.length();
    for(int i=0;i<a.length();i++){
        if('0'<=a[i]&&a[i]<='9'){
            b[cnt]=a[i]-'0';
            cnt++;
        }
    }
    sort(b,b+cnt);
    for(int j=cnt-1;j>=0;j--){
        ans+=b[j]*pow(10,j);
    }
    cout<<ans;
    return 0;
}
