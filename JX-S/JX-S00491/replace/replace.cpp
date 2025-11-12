#include<iostream>
#include<fstream>
#include<string>
using namespace std;
string lf[200001];
string rf[200001];
int dif[200001];
int firdi[200001];
int n,q;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>lf[i]>>rf[i];
        for(int j=0;j<lf[i].size();j++)
        {
            if(lf[i][j]!=rf[i][j])
            {
                dif[i]++;
                if(dif[i]==1)
                {
                    firdi[i]=j;
                }
            }
        }
    }
    for(int kivi=1;kivi<=q;kivi++)
    {
        int ans=0;
        string tm1,tm2;
        cin>>tm1>>tm2;
        int difer=0;
        int fidir;
        for(int i=0;i<tm1.size();i++)
        {
            if(tm1[i]!=tm2[i])
            {
                difer++;
                if(difer==1)
                {
                    fidir=i;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(difer==dif[i])
            {
                if(lf[i][firdi[i]]==tm1[fidir]&&rf[i][firdi[i]]==tm2[fidir]&&tm1.size()>=lf[i].size())
                {
                    int stre=fidir-firdi[i];
                    if(stre<0) continue;
                    for(int j=0;j<lf[i].size();j++)
                    {
                        if(stre+j>=tm1.size()) continue;
                        if(tm1[stre+j]!=lf[i][j]||rf[i][j]!=tm2[stre+j])
                        {
                            continue;
                        }
                    }
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
