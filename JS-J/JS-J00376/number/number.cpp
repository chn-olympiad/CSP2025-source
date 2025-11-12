#include <bits/stdc++.h>
using namespace std;
string a;
long long b[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;

    long long d=-1;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            ++d;
            b[d]=(long long)(a[i]-'0');


        }
    }

    sort(b,b+d+1);
    for(int i=d;i>=0;i--){
        cout<<b[i];
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
