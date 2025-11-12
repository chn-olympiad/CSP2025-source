#include<bits/stdc++.h>
using namespace std;
int a[1000010],n,m=1;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.size();i++)
    {
        n=s[i];
        if(48<=n&&n<=57){
            a[m]=n-48;
            m++;
        }
    }
    sort(a+1,a+m+1);
    for(int i=m;i>1;i--)
    {
        cout<<a[i];
    }
    return 0;
}
//48-57
