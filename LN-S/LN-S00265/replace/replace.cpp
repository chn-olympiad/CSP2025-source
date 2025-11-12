#include<bits/stdc++.h>
using namespace std;

int n,q;
vector<string> s1,s2;

int f(string t1,string t2,int p)
{
    int cnt=0;
    string w1=s1[p],w2=s2[p];
    if(w1.size()>t1.size()) return 0;

    for(int i=0;i+w1.size()<=t1.size();i++)
    {
        string tf1=t1;
        tf1.replace(i,w1.size(),w2);
        if(t1.substr(i,w1.size())==w1)
        {
            //cout<<t1<<' '<<w1<<' '<<tf1<<endl;
            if(tf1==t2) cnt++;
        }
    }
    return cnt;

}

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        string t1,t2;
        cin>>t1>>t2;
        s1.push_back(t1);
        s2.push_back(t2);
    }

    while(q--)
    {
        string t1,t2;
        cin>>t1;
        cin>>t2;
        if(t1.size()!=t2.size())
        {

            cout<<0<<endl;
            continue;
        }
        int ans=0;

        for(int i=0;i<n;i++)
        {

            ans+=f(t1,t2,i);
        }
        cout<<ans<<endl;
    }


    return 0;
}
