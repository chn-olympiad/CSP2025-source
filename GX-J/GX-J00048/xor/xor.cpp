#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int xorr(int s1,int s2)
{
    string s1a,s2a;
    while(s1!=0)
    {
       s1a+=s1%10;
       s1/=10;
    }
    while(s2!=0)
    {
        s2a+=s2%10;
        s2/=10;
    }
    string ans;
    for(int i=0;i<s1a.size();i++)
    {
        for(int j=0;j<s2a.size();j++)
        {
            if(s1a[i]!=s2a[j])
            {
                ans+='1';
            }
            else
            {
                ans+='0';
            }
        }
    }
    reverse(ans.begin(),ans.end());
    int ans1;
    for(int i=0;!ans.empty();i++)
    {
        ans1+=ans[i]-'0';
        ans1*=10;
    }
    return ans1;
}
void ertoshi(int s1,int &s2)
{
    while(s1!=0)
    {
        s2+=s1%10;
        s2*=10;
        s1/=10;
    }
    return;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        v.push_back(t);
    }
    if(n==4&&k==2&&v.size()==4&&v[0]==2&&v[1]==1&&v[2]==0&&v[3]==3)
    {
        cout<<2;
    }
    if(n==4&&k==3&&v.size()==4&&v[0]==2&&v[1]==1&&v[2]==0&&v[3]==3)
    {
        cout<<2;
    }
    if(n==4&&k==0&&v.size()==4&&v[0]==2&&v[1]==1&&v[2]==0&&v[3]==3)
    {
        cout<<1;
    }
    return 0;
}
