#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    freopen("number.in","w",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    vector<int>ve;
    int num=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            num++;
            ve.push_back(a[i]-'0');
        }
    }
    sort(a.begin(),a.end());
    for(int i=num-1;i>=0;i--)
    {

        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
