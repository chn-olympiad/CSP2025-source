#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    string huanqian[n];
    string huanhou[n];
    string wenti[q];
    string wentihou[q];
    int geshu=0;
    for(int x=0;x<n;x++)
    {
        cin>>huanqian[x]>>huanhou[x];
    }
    for(int x=0;x<q;x++)
    {
        geshu=0;
        cin>>wenti[x]>>wentihou[x];
        for(int y=0;y<n;y++)
        {
                int start=-1;
                for(int i=0;i<wenti[x].size();i++)
                {
                    if(wenti[x][i]==huanqian[y][0])
                    {
                        start=i;
                    }
                    else if(((i-start)>huanqian[y].size()-1 && start!=-1)|| i==wenti[x].size()-1 && start!=-1)
                    {
                        geshu++;
                        start=-1;
                    }
                    else if((wenti[x][i]!=huanqian[y][i-start] && start!=-1)||(wentihou[x][i]!=huanhou[y][i-start] && start!=-1))
                    {
                        start=-1;
                    }
                }
        }
        cout<<geshu<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
