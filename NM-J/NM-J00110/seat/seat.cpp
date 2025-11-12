#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{

    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int shu=n*m;
    vector<int> shuzu;
    int seat[n][m];
    int linshi;
    int aa1;
    cin>>aa1;
    shuzu.push_back(aa1);
    for(int i=1;i<shu;i++)
    {
        cin>>linshi;
        shuzu.push_back(linshi);
    }
    sort(shuzu.begin(),shuzu.begin()+shuzu.size(),cmp);
    int countt=0;
    bool flaggg=true;
    for(int i=1;i<=m;i++)
    {
        if(i%2==1)
        {
            for(int j=0;j<n;j++)
            {
                seat[j][i-1]=shuzu[countt];
                if(shuzu[countt]==aa1)
                {
                    cout<<i<<' '<<j+1;
                    flaggg=false;
                    break;
                }
                countt++;
            }
        }
        else
        {
            for(int j=n;j>0;j--)
            {
                seat[j-1][i-1]=shuzu[countt];
                if(shuzu[countt]==aa1)
                {
                    cout<<i<<' '<<j;
                    flaggg=false;
                    break;
                }
                countt++;
            }
        }
        if(!flaggg)
        {
            break;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
