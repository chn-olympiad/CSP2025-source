#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    int n;
    for(int i=0;i<t;i++)
    {
        vector<int> people;
        cin>>n;
        vector<int> scorea;
        vector<vector<int>> vvi;
        int a,b,c;
        people.push_back(0);
        people.push_back(0);
        people.push_back(0);
        if(n==2)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a>>b>>c;
                vvi.push_back({a,b,c});
            }
            vector<int> shuzu;
            for(int j=0;j<3;j++)
            {
                for(int m=0;m<3;m++)
                {
                    if(m!=j)
                    {
                        shuzu.push_back(vvi[0][j]+vvi[1][m]);
                    }
                }
            }
            sort(shuzu.begin(),shuzu.begin()+shuzu.size(),cmp);
            cout<<shuzu[0];
        }
        else
        {
            for(int j=0;j<n;j++)
            {
                cin>>a>>b>>c;
                scorea.push_back(a);
            }
            sort(scorea.begin(),scorea.begin()+scorea.size(),cmp);
            int he=0;
            for(int j=0;j<n;j++)
            {
                he+=scorea[j];
            }
            cout<<he<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
