#include<bits/stdc++.h>
using namespace std;
string sum[10050][3];
string a1,b1;
int ans;
int main()
{
    //freopen("replace.in","r",stdin);
    //freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>sum[i][1]>>sum[i][2];
    }
    cin>>a1>>b1;
    for(int i=1;i<=n;i++)
    {
        bool f,f1;
        string a=sum[i][1];
        string b=sum[i][2];
        int num=a.size();
        int num1=b.size();
        for(int j=num;j<=n;j++)
        {
            string u="";
            for(int v=1;v<=num;v++)
            {
                u+=a1[v-1];
            }
            if(u==a)
            {
                f=1;
                break;
            }
        }
        for(int j=num1;j<=n;j++)
        {
            string u="";
            for(int v=1;v<=num1;v++)
            {
                u+=b1[v-1];
            }
            if(u==b)
            {
                f1=1;
                break;
            }
        }
        if(f==1&&f1==1)
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
