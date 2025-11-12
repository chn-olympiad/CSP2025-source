#include<bits/stdc++.h>
using namespace std;
string n1[100001],q1[100001],n2[100001],q2[100001];
int main()
{
    cin.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>q>>n;
    for(int i=0;i<n;i++)
    {
        cin>>n1[i]>>n2[i];
    }
    for(int i=0;i<q;i++)
    {
        cin>>q1[i]>>q2[i];
    }
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        for(int j=0;j<q;j++)
        {
            string n1c=n1[i],n2c=n2[i];
            if(n1c.find(q1[j])==0&&n2c.find(q2[j])==0)
            {
                n1c.erase(0,q1[j].length());
                n2c.erase(0,q2[j].length());
                if(n1c==n2c)
                {
                    cnt++;
                }
                continue;
            }
            while(n1c[0]==n2c[0])
            {
                n1c.erase(0,1);
                n2c.erase(0,1);
            }
            if(n1c.find(q1[j])!=0||n2c.find(q2[j])!=0)
            {
                continue;
            }
            n1c.erase(0,q1[j].length());
            n2c.erase(0,q2[j].length());
            if(n1c==n2c)
            {
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}
