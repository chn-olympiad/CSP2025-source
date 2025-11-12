#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;

string a;
int b[N];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>a;
    int cnt=0;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            b[++cnt]=a[i]-'0';
        }
    }
    for(int i=0;i<cnt;i++){
        sort(b,b+cnt);
    }
    for(int i=0;i<cnt;i++){
        cout<<b[cnt-i];
    }


    return 0;
}
