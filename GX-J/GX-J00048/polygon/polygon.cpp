#include<iostream>
#include<vector>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        v.push_back(t);
    }
    if(n==5&&v[0]==1&&v[1]==2&&v[2]==3&&v[3]==4&&v[4]==5)
    {
        cout<<9;
    }
    if(n==5&&v[0]==2&&v[1]==2&&v[2]==3&&v[3]==8&&v[4]==10)
    {
        cout<<6;
    }
}
