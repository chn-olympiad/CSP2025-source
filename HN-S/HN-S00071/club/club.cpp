#include<bits/stdc++.h>
using namespace std;
const int Max = 1e5 + 5;



struct WOW
{
    int n,m;
    int a[Max],b[Max] , c[Max];
//    int mmax;
    int ant = 0;

//    void DFS(int now,int na,int nb,int nc,int val)
//    {
//        if(na >mmax ||nb > mmax || nc > mmax )
//            return ;
//        if(now == n)
//        {
//            ant = max(ant , val);
//            return ;
//        }
//        DFS(now + 1,na + 1,nb,nc,val + a[now]);
//        DFS(now + 1,na,nb + 1,nc,val + b[now]);
//        DFS(now + 1,na,nb,nc + 1,val + c[now]);
//    }
//    void baoli()
//    {
//        cin >>n;
//        mmax = n >> 1;
//        for(int q=0;q <n;q++)
//        {
//            cin >>a[q] >>b[q] >>c[q];
//        }
//        DFS(0,0,0,0,0);
//        
//        cout <<ant <<endl;
//    }
    int aa=0,bb=0,cc = 0;
    vector<int>av,bv,cv;
    void Solve()
    {
        cin >>n;
        for(int q=0;q <n;q++)
        {
            cin >>a[q] >>b[q] >>c[q];
            int mmax = max({a[q],b[q],c[q]});
            ant += mmax;
            if(a[q] == mmax)
            {
                av.push_back(q);
                aa++;continue;
            }
            if(b[q] == mmax)
            {
                bv.push_back(q);
                bb++;continue;
            }
            if(c[q] == mmax)
            {
                cv.push_back(q);
                cc++;continue;
            }
        }
        if(aa > (n/2))
        {
            vector<int>ve;
            for(auto now : av)
            {
                int ww = a[now] - max(b[now],c[now]);
                ve.push_back(ww);
            }
            sort(ve.begin(),ve.end());
            for(int q=0;q < aa - (n / 2);q++)
                ant -= ve[q];
        }if(bb > (n/2))
        {
            vector<int>ve;
            for(auto now : bv)
            {
                int ww = b[now] - max(a[now],c[now]);
                ve.push_back(ww);
            }
            sort(ve.begin(),ve.end());
            for(int q=0;q < bb - (n / 2);q++)
                ant -= ve[q];
        }
        if(cc > (n/2))
        {
            vector<int>ve;
            for(auto now :cv)
            {
                int ww = c[now] - max(a[now],c[now]);
                ve.push_back(ww);
            }
            sort(ve.begin(),ve.end());
            for(int q=0;q < cc - (n / 2);q++)
                ant -= ve[q];
        }
        cout <<ant <<endl;
        
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int T = 1;
    cin >>T;
    while(T--)
    {
        WOW OWO;
        OWO.Solve();
    }


    return 0;
}
