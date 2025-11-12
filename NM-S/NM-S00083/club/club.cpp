#include <bits/stdc++.h>

using namespace std;


int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,t,k=0,son,stw,sth,c;
    int date[n+1][4];
    int re[n+1];


    cin>>t;
    while(k<t)
    {
        k++;
        cin>>n;
        int date[n+1][4];
        for(int i=0;i<n;++i)
        {
            cin>>date[i][1]>>date[i][2]>>date[i][3];
            //cout<<date[i][1]<<" "<<date[i][2]<<" "<<date[i][3]<<endl;
        }
        for(int j=0;j<n;++j)
        {
            //cout<<"jieguo:"<<max(date[j][1],date[j][2])<<".....";
            re[1]+=max(max(date[j][1],date[j][2]),max(date[j][2],date[j][3]));


        }
        cout<<re[1]<<endl;
        re[1]=0;

    }
    return 0;
}
