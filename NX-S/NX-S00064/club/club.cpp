#include <bits/stdc++.h>
using namespace std;

int a[100001][3],n;
bool stat[100001];

void calc(int A, int B, int C)
{
    int m[3];
    m[0] = 1;
    m[1] = 2001;
    m[2] = 0;
    if(A>n/2)
    {
        for(int i=1; i<=n; i++)
        {
            if(min(m[1],min(abs(a[i][0]-a[i][1]),abs(a[i][0]-a[i][2])))!=m[1]&&(a[i][0]||a[i][1]||a[i][2]))
            {
                m[0] = i;
                m[1] = min(abs(a[i][0]-a[i][1]),abs(a[i][0]-a[i][2]));
                if(min(abs(a[i][0]-a[i][1]),abs(a[i][0]-a[i][2]))==abs(a[i][0]-a[i][1]))
                {
                    m[2] = 1;
                }
                else
                {
                    m[2] = 2;
                }
            }
        }
        a[m[0]][0] = 0;
        A--;
    }
    else if(B>n/2)
    {
        for(int i=1; i<=n; i++)
        {
            if(min(m[1],min(abs(a[i][1]-a[i][2]),abs(a[i][1]-a[i][0])))!=m[1]&&(a[i][0]||a[i][1]||a[i][2]))
            {
                m[0] = i;
                m[1] = min(abs(a[i][1]-a[i][2]),abs(a[i][1]-a[i][0]));
                if(min(abs(a[i][1]-a[i][2]),abs(a[i][1]-a[i][0]))==abs(a[i][1]-a[i][2]))
                {
                    m[2] = 2;
                }
                else
                {
                    m[2] = 0;
                }
            }
        }
        a[m[0]][1] = 0;
        B--;
    }
    else if(C>n/2)
    {
        for(int i=1; i<=n; i++)
        {
            if(min(m[1],min(abs(a[i][2]-a[i][1]),abs(a[i][2]-a[i][0])))!=m[1]&&(a[i][0]||a[i][1]||a[i][2]))
            {
                m[0] = i;
                m[1] = min(abs(a[i][2]-a[i][1]),abs(a[i][2]-a[i][0]));
                if(min(abs(a[i][2]-a[i][1]),abs(a[i][2]-a[i][0]))==abs(a[i][2]-a[i][1]))
                {
                    m[2] = 1;
                }
                else
                {
                    m[2] = 0;
                }
            }
        }
        a[m[0]][2] = 0;
        C--;
    }
    else
    {
        int res=0;
        for(int i=1 ;i<=n; i++)
        {
            res += max(a[i][0],max(a[i][1],a[i][2]));
        }
        cout <<res<<endl;
        return ;
    }
    if(m[2]==2)
    {
        C++;
    }
    else if(m[2]==1)
    {
        B++;
    }
    else
    {
        A++;
    }
    calc(A,B,C);
    return ;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >>t;
    for(int k=0; k<t; k++)
    {
        int x=0,y=0,z=0;
        memset(a,sizeof(a),0);
        cin >>n;
        for(int i=1; i<=n; i++)
        {
            cin >>a[i][0]>>a[i][1]>>a[i][2];
            if(max(a[i][0],max(a[i][1],a[i][2]))==a[i][0])
            {
                x++;
            }
            else if(max(a[i][0],max(a[i][1],a[i][2]))==a[i][1])
            {
                y++;
            }
            else
            {
                z++;
            }
        }
        calc(x,y,z);

    }
    return 0;
}
