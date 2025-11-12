#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    getline(cin,a);
    int nm[11]={0};
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        nm[a[i]-'0']++;
    }
    for(int i=9;i>=0;i--)
    {
        for(;nm[i]>0;nm[i]--)
            cout<<i;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
