#include<bits/stdc++.h>
using namespace std;
string a;
long long k[15];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0' && a[i]<='9'){
            k[a[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        if(k[i]==0){
            continue;
        }
        while(k[i]>0){
            cout<<i;
            k[i]--;
        }
    }
    //cout<<fixed<<setprecision(3)<<a;
    return 0;
}
