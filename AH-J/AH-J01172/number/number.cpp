#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    int l=s.size();
    for(int i=0;i<l;++i)
    {
        if(s[i]>='0'&&s[i]<='9') ++a[s[i]-'0'];
    }
    bool oj=true;
    int i=9;
    while(i>=0)
    {
        if(i!=0)
        {
            if(a[i]>0) oj=false;
            while(a[i])
            {
                cout<<i;
                --a[i];
            }
        }
        else
        {
            if(oj==true) cout<<i;
            else
            {
                while(a[i])
                {
                    cout<<i;
                    --a[i];
                }
            }
        }
        --i;
    }
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
