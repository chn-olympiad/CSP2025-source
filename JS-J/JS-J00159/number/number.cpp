#include<bits/stdc++.h>
#define ll long long
using namespace std;
string n;
ll a[10],ans;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n;
    for(int i=0;i<n.size();i++)
    {
        if(n[i]=='1') a[1]++;
        if(n[i]=='2') a[2]++;
        if(n[i]=='3') a[3]++;
        if(n[i]=='4') a[4]++;
        if(n[i]=='5') a[5]++;
        if(n[i]=='6') a[6]++;
        if(n[i]=='7') a[7]++;
        if(n[i]=='8') a[8]++;
        if(n[i]=='9') a[9]++;
        if(n[i]=='0') a[0]++;
    }
    for(int i=9;i>=0;i--) for(int j=1;j<=a[i];j++) cout<<i;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
