#include <bits/stdc++.h>
using namespace std;
string s;
int a[100001],b[100001],n;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=s.size;
    for(int i=1;i<=n;i++){
        if(i=='1'||'2'||'3'||'4'||'5'||'6'||'7'||'8'||'9'){
            s[i]=b[i];
        }
        a[i]=b[i];
        sort(a+1,a+n+1);
    }
    cout<<a;
    return 0;
}
