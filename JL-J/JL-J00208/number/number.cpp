#include <bits/stdc++.h>
using namespace std;
const int N=1e6+7;
char a[N];
int b[N],ans;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","w",stdin);
    freopen("number.out","r",stdout);
    cin.getline(a,N);
    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]=='0')
            b[i]=0,ans++;
        if(a[i]=='1')
            b[i]=1,ans++;
        if(a[i]=='2')
            b[i]=2,ans++;
        if(a[i]=='3')
            b[i]=3,ans++;
        if(a[i]=='4')
            b[i]=4,ans++;
        if(a[i]=='5')
            b[i]=5,ans++;
        if(a[i]=='6')
            b[i]=6,ans++;
        if(a[i]=='7')
            b[i]=7,ans++;
        if(a[i]=='8')
            b[i]=8,ans++;
        if(a[i]=='9')
            b[i]=9,ans++;
    }
    sort(b,b+strlen(a),cmp);
    for(int i=0;i<ans;i++)
        cout<<b[i];
    return 0;
}
