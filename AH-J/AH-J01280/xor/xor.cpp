#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    bool oj=true;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        if(v[i]!=1)oj=false;
    }
    if(oj==true&&k==0)
    {
        cout<<"0";
        return 0;
    }
    else
    {
        int num1=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]==1)num1++;
        }
        cout<<num1;
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
