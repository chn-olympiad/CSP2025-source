#include<bits/stdc++.h>;
using namespace std;
long long n,q;
char s1[200045][2045],s2[200045][2045];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        long long cnt=0;
        while(cin>>s1[i][cnt] && s1[i][cnt]!=' ') cnt++;
        cnt=0;
        while(cin>>s2[i][cnt] && s1[i][cnt]!=' ') cnt++;
    }
    for(int k=1;k<=q;k++)
    {
        string t1,t2;
        long long cnt=0;
        cin>>t1>>t2;
        for(int i=1;i<n;i++)
        {
            if(t1.find(s1[i])!=-1) cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
