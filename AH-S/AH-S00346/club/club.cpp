#include<bits/stdc++.h>
using namespace std;

int t,n;
void feel(int m)
{
    int s[1000][3];
    int score[3]={0};
    int counts=0;
    for(int i=0;i<m;i++)
    {
        scanf("%d",&s[i][0]);
        scanf("%d",&s[i][1]);
        scanf("%d",&s[i][2]);
        if(s[i][0]>=s[i][1])
        {
            if(s[i][0]>=s[i][2])
            {
                maxs[i]=s[i][0];
                score[0]++;
            }
            else
            {
                maxs[i]=s[i][2];
                score[2]++;
            }
        }
        else
        {
            if(s[i][1]>=s[i][2])
            {
                maxs[i]=s[i][1];
                score[1]++;
            }
            else
            {
                maxs[i]=s[i][2];
                score[2]++;
            }
        }
        counts=counts+maxs[i];
    }
    if((score[0]<=n/2)&&(score[1]<=n/2)&&(score[2]<=n/2))
    {
        printf("%d",counts);
    }
}
