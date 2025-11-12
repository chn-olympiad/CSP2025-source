#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >>n;
    int lang[n];
    for(int i=0;i<=n-1;i++)
    {
        cin >>lang[i];
    }
    sort(lang,lang+n);
    if(lang[0]+lang[1]+lang[2]>lang[2]*2)
    {
        cout <<1;
    }
    else{
        cout <<0;
    }
    return 0;
}
