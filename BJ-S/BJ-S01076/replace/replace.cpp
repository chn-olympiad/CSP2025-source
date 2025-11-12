#include<bits/stdc++.h>

using namespace std;

struct change
{
    int left;
    int right;
    int cha;
};

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    change s[n];
    change t[q];
    int ans[q];
    for(int i=0;i<n;i++)
    {
        string a;
        string b;
        cin>>a>>b;
        bool aco=0;
        bool bco=0;
        int posa;
        int posb;
        for(int j=0;j<a.length();j++)
        {
            if(a[j]=='b')
            {
                s[i].left=j;
                s[i].right=a.length()-j-1;
                posa=j;
                aco=1;
            }
            if(b[j]=='b')
            {
                posb=j;
                bco=1;
            }
            if(aco==1&&bco==1)
            {
                break;
            }
        }
        s[i].cha=posb-posa;
    }
    for(int i=0;i<q;i++)
    {
        ans[i]=0;
        string x;
        string y;
        cin>>x>>y;
        bool xco=0;
        bool yco=0;
        int posx;
        int posy;
        for(int j=0;j<x.length();j++)
        {
            if(x[j]=='b')
            {
                t[i].left=j;
                t[i].right=x.length()-j-1;
                posx=j;
                xco=1;
            }
            if(y[j]=='b')
            {
                posy=j;
                yco=1;
            }
            if(xco==1&&yco==1)
            {
                break;
            }
        }
        t[i].cha=posy-posx;
        for(int z=0;z<n;z++)
        {
            if(t[i].cha==s[z].cha&&t[i].left>=s[z].left&&t[i].right>=s[z].right)
            {
                ans[i]++;
            }
        }
    }
    for(int i=0;i<q;i++)
    {
        cout<<ans[i]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}