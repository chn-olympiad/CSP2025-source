#include <bits/stdc++.h>
using namespace std;
int n,q,idxz,idxf,is,ans;
string s[200005][3],t[200005][3],z_,f_;
char zi[5000006],fu[5000006];
string is_zi(string z,string f)
{
    memset(zi,"",sizeof(zi));
    memset(fu,"",sizeof(fu));
    idxz=0,idxf=0,z_=z,f_=f;
    while (z_!="")
    {
        zi[idxz+1]=z_[0];
        z_-=z_[0];
        idxz++;
    }
    while (f_!="")
    {
        fu[idxf+1]=f_[0];
        f_-=f_[0];
        idxf++;
    }
    if (idxz>idxf)
    {
        return 0;
    }
    is=0;
    for (int j=1;j<=idxf;j++)
    {
        if (z[1]!=f[j])
        {
            continue;
        }
        else
        {
            is=j;
            break;
        }
    }
    if (is==0)
    {
        return 0;
    }
    for (int i=2;i<=idxz;i++)
    {
        if (z[i]!=f[i-1+j])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    freopen('replace.in','r',stdin);
    freopen('replace.out','w',stdout);
    cin >> n >> q;
    for (int i=1;i<=n;i++)
    {
        cin >> s[i][1] >> s[i][2];
    }
    for (int i=1;i<=q;i++)
    {
        cin >> t[i][1] >> t[i][2];
    }
    for (int i=1;i<=q;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (is_zi(s[j][1],t[i][1])==1)
            {
                for (int k=0;k<=-1+idxz;k++)
                {
                    t[i][1][is+k]=s[j][1][1+k];
                }
                if (t[i][1]==t[i][2])
                {
                    ans++;
                }
            }
            if (is_zi(s[j][2],t[i][1])==1)
            {
                for (int k=0;k<=-1+idxz;k++)
                {
                    t[i][1][is+k]=s[j][2][1+k];
                }
                if (t[i][1]==t[i][2])
                {
                    ans++;
                }
            }

        }
    }
    cout << ans;
    return 0;
}
