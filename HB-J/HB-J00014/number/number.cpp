#include <bits/stdc++.h>
using namespace std;
int a[1000005],p=-1e9;
char s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(cin>>s){
        if(s<='9' and s>='0'){
            a[s-'0']++;p=max(p,s-'0');
        }
    }
    for(int i=p;i>=0;i--){
        for(int j=0;j<a[i];j++){
            cout<<i;
        }
    }
    return 0;
}
