#include <bits/stdc++.h>
using namespace std;
const int N=1e6+6;
char a[N];
int nu[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    int lenu=0;
    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]>='0' && a[i]<='9')
        {
            lenu++;
            nu[lenu]=(a[i]-'0');
        }
    }
    sort(nu+1,nu+lenu+1);
    for(int i=lenu;i>=1;i--)
    {
        cout<<nu[i];
    }
    return 0;
}
