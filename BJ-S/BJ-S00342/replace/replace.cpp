#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rof(i,a,b) for(int i=a;i>=b;i--)
#define fs first
#define sc second
using namespace std;
const int NN=2e5+5,M=2e6+5;
int n,m,q;
string s,t[NN],p[NN];
int visl[M],visr[M];
vector<int> fail1[NN],fail2[NN];
int flg=0;
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    cin>>n>>q;
    For(i,1,n)
    {
        cin>>t[i]>>p[i];
    }
    For(i,1,n)
    {
        int pos=0;
        m=t[i].size();
        t[i]=' '+t[i];
        fail1[i].push_back(0);
        fail1[i].push_back(0);
        For(j,1,m-1)
        {
            while(pos&&t[i][pos+1]!=t[i][j+1])pos=fail1[i][pos];
            if(t[i][pos+1]==t[i][j+1])pos++;
            fail1[i].push_back(pos);
        }
    }
    For(i,1,n)
    {
        int pos=0;
        m=p[i].size();
        p[i]=' '+p[i];
        fail2[i].push_back(0);
        fail2[i].push_back(0);
        For(j,1,m-1)
        {
            while(pos&&p[i][pos+1]!=p[i][j+1])pos=fail2[i][pos];
            if(p[i][pos+1]==p[i][j+1])pos++;
            fail2[i].push_back(pos);
            // cout<<i+1<<' '<<pos<<endl;
        }
    }
    while(q--)
    {
        int ans=0;
        string S,T;cin>>S>>T;
        S=' '+S,T=' '+T;
        int kkk=S.size()-1;
        For(i,0,kkk+1)visl[i]=visr[i]=0;
        visl[0]=1;
        For(i,1,kkk)
        {
            if(S[i]!=T[i])break;
            visl[i]=1;
        }
        visr[kkk+1]=1;
        Rof(i,kkk,1)
        {
            if(S[i]!=T[i])break;
            visr[i]=1;
        }
        For(i,1,n)
        {
            vector<int> v1,v2;
            int len=S.size()-1;
            int m=t[i].size()-1;
            int pos=0;
            For(j,1,len)
            {
                // cout<<j<<endl;
                while(pos&&t[i][pos+1]!=S[j])pos=fail1[i][pos];
                if(t[i][pos+1]==S[j])pos++;
                if(pos==m)
                {
                    v1.push_back(j);
                    pos=fail1[i][pos];
                }
            }
            len=T.size()-1;
            m=p[i].size()-1;
            pos=0;
            For(j,1,len)
            {
                // cout<<i<<endl;
                while(pos&&p[i][pos+1]!=T[j])pos=fail2[i][pos];
                if(p[i][pos+1]==T[j])pos++;
                if(pos==m)
                {
                    v2.push_back(j);
                    pos=fail2[i][pos];
                }
            }
            int l=0;
            if(v1.size()==0||v2.size()==0)continue;
            // cout<<v1.size()<<' '<<v2.size()<<endl;
            // for(auto awa:v1)cout<<awa<<' ';
            // cout<<endl;
            for(int awa=0;awa<(int)v1.size();awa++)
            {
                int oh=v1[awa];
                while(l<(int)v2.size()&&v2[l]<oh)l++;
                // cout<<awa<<endl;
                if(oh==v2[l])
                {
                    // cout<<oh<<' '<<t[i].size()-1<<endl;
                    if(visl[oh-(int)t[i].size()+1]==1&&visr[oh+1]==1)
                    {
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}