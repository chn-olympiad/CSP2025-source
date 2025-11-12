#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n;
    int a;
    cin>>n;
    cin>>a;
    string all[n+1];
    string all2[n+1];
    string zong[a+1];
    string zong2[a+1];
    for (int i=1;i<=n;i++)
    {
        cin>>all[i];
        cin>>all2[i];
    }
    for (int i=1;i<=a;i++)
    {
        cin>>zong[i];
        cin>>zong2[i];
    }
    for (int i=1;i<=a;i++)
    {
        int sum = 0;
        int pos = 0;
        string diff[3];
        int k = zong[i].size();
        int place[k];
        int last = 0;
        int start = 0;
        for (int s = 0;s<k;s++)
        {
            place[s]=0;
        }
        for (int j=0;j<k;j++)
        {
            if(zong[i][j]!=zong2[i][j])
            {
                place[j]++;
                last=j;
            }
        }
        for(int p=0;p<k;p++)
        {
            if(place[p]==1)
            {
                start = p;
                break;
            }
        }
        for (int p = start;p<=last;p++)
        {
            diff[1]+=zong[i][p];
            diff[2]+=zong2[i][p];
        }


        cout<<sum<<endl;

    }

}
