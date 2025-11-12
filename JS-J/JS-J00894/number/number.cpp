#include <bits/stdc++.h>
using namespace std;
const int N=1e6+2;
int b[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    long long len=a.size();
    int cnt=0;
    for(long long i =0;i<len;i++){
        if(a[i]>='0'&&a[i]<='9'){

            b[cnt]=a[i]-'0';
            cnt++;
        }
    }
    sort(b-1,b+cnt);
    for(int i =cnt-1;i>=0;i--){
        cout<<b[i];
    }
    return 0;
}
