#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string ss;
    cin>>ss;
    long long v=0;
    for(long long i=0;i<ss.size();i++){
        if(ss[i]>='0'&&ss[i]<='9'){
            a[v]=ss[i]-'0';
            v++;
        }
    }
    sort(a,a+v);
    for(long long i=v-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}

