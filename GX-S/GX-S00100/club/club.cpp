#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
constexpr int Mn=1e5+11,oo=1e9;
struct I
{
    int C,W;
    bool operator < (const I& k)const
    {
        return C>k.C;
    }
};
struct I2
{
    int C,W,x;
    bool operator < (const I2& k)const
    {
        return C>k.C;
    }
}l;
struct CO2{I A[3];}c[Mn];
priority_queue<I2> q[3];
int n;
long long y;  // The answer must be very big.
void C()
{
    int i,w;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>c[i].A[0].C>>c[i].A[1].C>>c[i].A[2].C;
        c[i].A[0].W=0; // duo zu shu ju yao qing kong .
        c[i].A[1].W=1;
        c[i].A[2].W=2;
        sort(c[i].A,c[i].A+3);
    }
    for(i=1;i<=n;i++)
    {
        if(q[ c[i].A[0].W ].size()<n/2)
            q[ c[i].A[0].W ].push({ c[i].A[0].C-c[i].A[1].C , i , 0   });
        else
        {
            l=q[ c[i].A[0].W ].top();
            if(l.x==2)
            {
                q[ c[i].A[1].W ].push({ c[i].A[1].C-c[i].A[2].C , i , 1  });
                continue;
            }
            if( l.C <  c[i].A[0].C - c[i].A[1].C )
            {
                q[ c[i].A[0].W ].pop();
                q[ c[i].A[0].W ].push({ c[i].A[0].C-c[i].A[1].C , i , 0 });
                if(l.x==0)w=c[l.W].A[l.x+1].C-c[l.W].A[l.x+2].C;
                else w=oo;
                q[ c[l.W].A[l.x+1].W ].push({ w , l.W , l.x+1  });
            }
            else q[ c[i].A[1].W ].push({ c[i].A[1].C-c[i].A[2].C , i , 1  });
        }
    }
    y=0;
    for(i=0;i<3;i++)
    {
        while(!q[i].empty())
        {
            l=q[i].top();
            q[i].pop();
            y+=c[ l.W ].A[l.x].C;
        }
    }
    cout<<y<<'\n';
}  // duo zu bu qing kong , OI yi chang kong .
int main()
{//       Important .
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)C();
    return 0;
}
