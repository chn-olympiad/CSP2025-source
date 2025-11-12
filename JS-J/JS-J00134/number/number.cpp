#include<bits/stdc++.h>
using namespace std;
string a;
long long tong[11],sum[1000001],cnt=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<=a.size()-1;i++){
        if(a[i]-'0'>=0&&a[i]-'0'<=9){
            tong[a[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        if(tong[i]<=0){
            continue;
        }
        for(int j=1;j<=tong[i];j++){
            cnt++;
            sum[cnt]=i;
        }
    }
    for(int i=1;i<=cnt;i++){
        cout<<sum[i];
    }
    return 0;
}
