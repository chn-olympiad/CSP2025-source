#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    vector<string> s[2];
    for(int i=0 ; i<n;i++)
    {
        string t1,t2;
        cin>>t1>>t2;
        s[0].push_back(t1);
        s[1].push_back(t2);
    }
    if(n<50005)
    {
        while(q--)
        {
            string ans1,ans2;
            cin>>ans1>>ans2;
            int cnt=0;
            for(int i=0;i<n;i++)
            {
                string r1=ans1,r2=ans2;
                int p=r1.find(s[0][i]);
                if(p==-1) continue;
                int f=0,z=0;
                for(int j=p;j<p+s[0][i].size();j++)
                {
                    if(s[1][i][z]!=r2[j]) f=2;
                    z++;
                    r1[j]='1',r2[j]='1';
                }
                if(f==2 or r1!=r2) continue;
                cnt++;
            }
            cout<<cnt<<endl;
        }
    }
    else{
        while(q--)
        {
            string ans1,ans2;
            int f=0;
            for(int i=0;i<n;i++)
            {
                if(ans1==s[0][i] and ans2==s[1][i])
                {
                    cout<<1;
                    f=1;
                    break;
                }
            }
            if(f==0) cout<<0;
        }
    }

	return 0;
}
