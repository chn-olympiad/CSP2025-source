#include <bits/stdc++.h>
using namespace std;
int n,q;
string con[20002][2];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        cin>>con[i][0]>>con[i][1];
    }
    for(int i=0;i<q;i++)
    {
        int sum=0;
        string a,b;
        cin>>a>>b;
        if(a.length()!=b.length())
        {
            cout<<0<<endl;
            continue;
        }
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<a.length();k++)
            {
                for(int l=k+1;l<=a.length();l++)
                {
                    string s=a.substr(k,l-k);
                    string s1=a.substr(0,k);
                    string s2=a.substr(l,a.length()-l);
                    string q1=b.substr(0,k);
                    string q2=b.substr(l,b.length()-l);
                    string q3=b.substr(k,l-k);
                    if(s==con[j][0]&&s1==q1&&s2==q2&&q3==con[j][1])sum++;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}