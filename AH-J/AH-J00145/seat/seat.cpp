#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    bool flag=false;
    cin>>n>>m;
    int num[n][m],w=n*m,goal[w];
    for(int i=0;i<n*m;i++)
        cin>>goal[i];
    int aim=goal[0];
    sort(goal,goal+w);
    int hang=0;
    for(int lie=0;lie<m;lie++)
    {
        if(hang<=0)
        {
            for(;hang<n;hang++)
            {
                if(goal[w-1]==aim)
                {
                    w--;
                    cout<<(lie+1)<<" "<<(hang+1);
                    flag=true;
                    break;
                }
                w--;
            }
            hang--;
            if(flag)
            {
                break;
            }else{
                continue;
            }
        }
        else
        {
            for(;hang>=0;hang--)
            {
                if(goal[w-1]==aim)
                {
                    w--;
                    cout<<(lie+1)<<" "<<(hang+1);
                    flag=true;
                    break;
                }
                w--;
            }
            hang++;
            if(flag)
            {
                break;
            }else{
                continue;
            }
        }


    }
    return 0;
}

