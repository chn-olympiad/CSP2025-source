#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin >>n>>q;
    int maxa=0;
    char a[n][1000];
    char b[n][1000];
    for(int i=0;i<=n-1;i++)
    {
        cin >>a[i]>>b[i];
    }
    char qs1[10000];
    char qs2[10000];
    for(int i=0;i<=q-1;i++)
    {
        cin >>qs1>>qs2;
        for(int i=0;i<=n-1;i++)
        {
            for(int j=0;j<=strlen(qs1)-strlen(a[i]);j++)
            {
                if(a[i][0]==qs1[j])
                {
                    char c[n];
                    char d[n];
                    strcpy(c,qs1);
                    strcpy(d,qs2);
                    for(int o=j;o<=j+strlen(a[i])-1;o++)
                    {
                        qs1[o]=b[i][o-j];
                    }
                    for(int o=0;o<=strlen(qs1);o++)
                    {
                        if(o==strlen(qs1))
                        {
                            maxa++;
                            break;
                        }
                        if(qs1[o]==qs2[o])
                        {
                            continue;
                        }
                        break;
                    }
                    strcpy(qs1,c);
                    strcpy(qs2,d);
                }
            }
        }

    }
    cout <<maxa;
    return 0;
}
