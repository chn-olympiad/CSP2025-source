#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,q;
struct node
{
    string a,b;
}s[N];
int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>s[i].a>>s[i].b;
    while(q--)
    {
        string st,ed;
        cin>>st>>ed;
        for(int l=0;l<st.size();l++)
        {
            string now;
            for(int r=l;r<st.size();r++)
            {
                now+=st[r];
                for(int i=1;i<=n;i++)
                    if(s[i].a==now)
            }
        }

    }
    return 0;
}
