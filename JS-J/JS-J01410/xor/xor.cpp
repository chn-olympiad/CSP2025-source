#include<bits/stdc++.h>
using namespace std;
struct node
{
    int st;
    int en;
};
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k ;
    int xo[n+2]={};
    vector<node> v;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> xo[i];
        xo[i]^=xo[i-1];
       // cout << xo[i] << " ";
        for(int j =  i  ;j>=1 ; j --)
        {
             if(int(xo[i]^xo[j-1])==k)
             {
                 node x;
                 x.st=j;
                 x.en=i;
                 v.push_back(x);
                 //cout << x.st <<" " << x.en << " " << int(xo[i]^xo[j-1]) << endl;
                 break;
             }
        }
    }
     int e = 0;
     int ans = 0 ;

     for(int i = 0 ; i < v.size();i++)
     {
         if(v[i].st>e)
         {
             e=v[i].en;
             ans++;
         }
          // cout << v[i].st << " " << v[i].en << endl;
     }
     cout << ans;
    return 0 ;
}
