#include<bits/stdc++.h>
using namespace std;
int N=1E+5;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.ans","w",stdout);
    int t;
    int T;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        int a[3];
        int n;
        int MAX=0;int sum=0;
        cin>>n;
        int Y=n/2;
        for(int i=0;i<n;i++)
        {  for(int o=0;o<3;o++)
            {
                cin>>a[o];
                MAX=max(MAX,a[o]);
            }
            sum=sum+MAX;
        }
        cout<<sum<<endl;
    }
    return 0;
}
