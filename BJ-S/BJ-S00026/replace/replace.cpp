#include<bits/stdc++.h>
using namespace std;
int n,q,sum=0;
string s[200011],s2[200011],a[200011],b[200011];
int main()
{

    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>s[i]>>s2[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=q;i++)
    {
        sum=0;
        for(int j=1;j<=n;j++)
        {
            string t=a[j];
            for(int w=0;w+t.size()<=s[i].size();w++)
            {
                string t2(s[i],w,t.size());
                string t3(s2[i],w,t.size());
                //cout<<t2<<' '<<t3<<endl;
                if(t2==t&&t3==b[j])
                {
                    //cout<<j<<t<<w<<endl;
                    sum++;
                }
            }

        }
        cout<<sum<<endl;
    }
    return 0;
}
