#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    if(n<3)
    {
        cout<<"0";
        return 0;
    }
    sort(v.begin(),v.end());
    vector<int>s(n);s[0]=v[0];
    for(int i=1;i<n;i++)s[i]=s[i-1]+v[i];
    if(n==3)
    {
        if(s[n-1]>v[n-1]*2)
        {
            cout<<"1";
            return 0;
        }
        else
        {
            cout<<"0";
            return 0;
        }
    }

    //zhe ti sha yin???
    fclose(stdin);
    fclose(stdout);
    return 0;
}
