#include<bits/stdc++.h>
using namespace std;
const int Max = 1e5 + 5;



int num[11] ;
int to[11][Max];
vector<int> path[Max]; 
struct WOW
{
    int n,m,k;
    vector<pair<int,int> >path;
    
    void zero()
    {
        for(int u,v,w,q=0;q <m;q++)
        {
            cin >>u >>v >>w;
            path[u].push_back({v,w});
            path[v].push_back({u,w});
        }
        
        cout <<0 <<endl;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >>T;
    while(T--)
    {
        WOW OWO;
        cin >>OWO.n >>OWO.m >>OWO.k;
        if(OWO.k == 0)
            OWO.zero();
    }


    return 0;
}