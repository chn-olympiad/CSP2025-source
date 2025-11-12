#include<bits/stdc++.h>
using namespace std;

int n,m,non=0,nom=0,now;
int mn[1010];
int cx;
bool cmp(int z,int x){
    return z>x;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<m*n;i++)
    {
        cin>>mn[i];
    }
    int q=mn[0];
    sort(mn,mn+m*n,cmp);
    for(int i=0;i<n*m;i++)
    {
        if(mn[i]==q){
            now=i+1;
            break;
        }
    }
    for(;;non++)
    {
        if(now>m)now-=m;
        else{
            if(cx==1)
            {
                cout<<non+1<<' '<<m-now+1<<endl;
                return 0;
            }
            else{
                cout<<non+1<<' '<<now<<endl;
                return 0;
            }
        }
        cx+=1;
        cx%=2;
    }
}
