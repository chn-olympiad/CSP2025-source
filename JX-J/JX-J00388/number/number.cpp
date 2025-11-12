#include<bits/stdc++.h>
using namespace std;
string a;
long c,ac[1000006],s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    s=a.size();
    for(int i=0;i<s;i++){
        if(a[i]>='0' && a[i]<='9'){
            c++;
            ac[c]=a[i]-'0';
        }
    }
    sort(ac+1,ac+1+c);
    for(int i=c;i>=1;i--)cout<<ac[i];
    return 0;
}
