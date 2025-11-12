#include <bits/c++.h>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    long long n,m,fq,fa,z,tc;
    fa=1;
    z=0;
    cin>>n>>m;
    string s;
    cin>>s;
    int num[n];
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }

    sort(num,num+n);

    while(n!=0)
    {
        if(s[z]=="0" && num[z]>=fq)
        {
            for(int i=z;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(num[i]!=num[j])
                    {
                        for(int d=i;d<=j;d++)
                        {
                            fa*=d;
                            fa%=998244353;
                            tc=1;
                        }
                    }
                    if(tc!=0)
                    {
                        break;
                    }
                }
            }
        }
        else
        {
            fq++;
        }
        z++;
    }
    cout<<fa%998244353<<endl;
    return 0;
}

