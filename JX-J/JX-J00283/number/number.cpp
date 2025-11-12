#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long shu[1000005],ik = 1;
    string a;cin>>a;
    for(int i = 0;i<a.size();i++){
        if(a[i]>='0' && a[i]<='9'){
            shu[ik] = a[i] - '0';
            ik++;
        }
    }
    ik--;
    sort(shu+1,shu+ik+1);
    for(int i=ik;i>=1;i--){
        cout<<shu[i];
    }
    return 0;

}
