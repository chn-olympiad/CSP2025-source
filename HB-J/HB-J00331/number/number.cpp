#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    //mark greatest ZhuYunFan;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int v[1000006],j=1;
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]<='9'&&a[i]>='0'){
            v[j++]=a[i]-'0';
        }
    }
    sort(v+1,v+j);
    for(int i=j-1;i>=1;i--){
        printf("%lld",v[i]);
    }
    return 0;
}
