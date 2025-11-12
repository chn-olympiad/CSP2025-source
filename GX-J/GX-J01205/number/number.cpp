#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int k=0,m=s.length(),a[s.length()+2];
    for(int i=0;i<m;i++)
    {
        int n=int(s[i]);
        if(n>=48&&n<=57)
        {
            a[k]=n-48;k++;
        }
        else continue;
    }
    sort(a,a+k);
    for(int i=k-1;i>=0;i--) cout<<a[i];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
