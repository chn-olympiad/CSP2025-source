#include<bits/stdc++.h>
using namespace std;
    bool used[505];//0-free 1-used
    int cnt=0;
    vector<int> temp;
    int n;
    int arr[505];
    int mark[505];
void dfs(int ed)
{

    if(temp.size()==ed)
    {

        int cntlin=0;
        for(int i=0;i<temp.size();i++)
        {
            cntlin+=temp[i];
        }
        if(cntlin>2*temp[temp.size()-1])
        {
 //           for(int i=0;i<temp.size();i++)
 //           {
 //               cout<<temp[i]<<" ";
 //           }
 //           cout<<cntlin<<"\n";
            cnt++;
        }

        return;
    }
    for(int i=0;i<n;i++)
    {
        i=i+mark[i]-1;
        bool f=0;
        if(temp.empty())
            f=1;
        else if(arr[i]>=temp.back())
            f=1;
        if(!used[i] && f)
        {
            temp.push_back(arr[i]);
            used[i]=1;
            dfs(ed);
            temp.pop_back();
            used[i]=0;
        }
    }
}
int main()
{
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
        freopen("polygon.in","r",stdin);
        freopen("polygon.out","w",stdout);

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int lin;
    for(int i=0;i<n;i++)
    {
        lin=1;
        if(arr[i]==arr[i+1] && i+1<n)
        {
            lin++;
        }
        else
            mark[i]=lin;
    }
    for(int ed=3;ed<=n;ed++)
    {
        dfs(ed);
    }
    cout<<cnt%998244353;
    cout<<"\n";
    return 0;
}
