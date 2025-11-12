#include<bits/stdc++.h>
using namespace std;
void run()
{
    bool flag=true;
    int n,q;
    cin>>n>>q;
    vector<string> s1(n),s2(n);
    vector<int> v1(n),v2(n);
    for(int i=0;i<n;i++)
    {
        cin>>s1[i]>>s2[i];
        if(flag)
        {
            int cnta=0,cntb=0;
            for(auto&j:s1[i])
            {
                if(j=='b')cntb++,v1[i]=&j-&s1[i][0];
                if(j=='a')cnta++;
            }
            if(cnta+cntb!=s1[i].size()||cntb!=1)
            {
                flag=false;
                continue;
            }
            cnta=cntb=0;
            for(auto&j:s2[i])
            {
                if(j=='b')cntb++,v2[i]=&j-&s2[i][0];
                if(j=='a')cnta++;
            }
            if(cnta+cntb!=s2[i].size()||cntb!=1)
            {
                flag=false;
            }
        }
    }
    vector<string> qs1(q),qs2(q);
    vector<int> vs1(q),vs2(q);
    for(int i=0;i<q;i++)
    {
        cin>>qs1[i]>>qs2[i];
        if(flag)
        {
            int cnta=0,cntb=0;
            for(auto&j:qs1[i])
            {
                if(j=='b')cntb++,vs1[i]=&j-&qs1[i][0];
                if(j=='a')cnta++;
            }
            if(cnta+cntb!=qs1[i].size()||cntb!=1)
            {
                flag=false;
                continue;
            }
            cnta=cntb=0;
            for(auto&j:qs2[i])
            {
                if(j=='b')cntb++,vs2[i]=&j-&qs2[i][0];
                if(j=='a')cnta++;
            }
            if(cnta+cntb!=qs2[i].size()||cntb!=1)
            {
                flag=false;
            }
        }
    }
    //for(auto&i:v1)cout<<i<<" ";
    //cout<<"\n";
    //for(auto&i:v2)cout<<i<<" ";
    //cout<<"\n";
    if(flag)
    {
        for(int i=0;i<q;i++)
        {
            int ans=0;
            int frqs1=vs1[i],edqs1=qs1[i].size()-frqs1-1;
            int frqs2=vs2[i],edqs2=qs2[i].size()-frqs2-1;
            for(int j=0;j<n;j++)
            {
                int frs1=v1[j],eds1=s1[j].size()-frs1-1;
                int frs2=v2[j],eds2=s2[j].size()-frs2-1;
                //cout<<i<<" "<<j<<" "<<frs1<<" "<<eds1<<" "<<frs2<<" "<<eds2<<" "
				//					<<frqs1<<" "<<edqs1<<" "<<frqs2<<" "<<edqs2<<"\n";
                if(frqs2>=frs2&&frqs1>=frs1&&edqs2>=eds2&&edqs1>=eds1&&frs1-frs2==frqs1-frqs2) ans++;
            }
            cout<<ans<<"\n";
        }
        return;
    }
    string a,b;
    for(int i=0;i<q;i++)
    {
        int ans=0;
        a=qs1[i],b=qs2[i];
        for(int i=0;i<n;i++)
        {
            int s=0,tp;
            while((tp=a.find(s1[i],s))!=string::npos)
            {
                if(b==a.substr(0,tp)+s2[i]+a.substr(tp+s1[i].size()))
                {
                    ans++;
                }
                s=tp+1;
            }
        }
        cout<<ans<<"\n";
    }
}

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    run();

    return 0;
}
/*

*/
