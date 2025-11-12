#include<bits/stdc++.h>
#define pii pair<unsigned long long,unsigned long long>
using namespace std;
const int N=2e5+6,M=5e6+6;
char a[M],b[M];
unsigned long long ha[N],ha2[N],base=13331,qz[M],qz2[M],po[M],len[N];
int id[N];
pii suan(int l,int r)
{
    return make_pair(qz[r]-qz[l-1]*po[r-l+1],qz2[r]-qz2[l-1]*po[r-l+1]);
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int nn,q;
    cin>>nn>>q;
    for(int ii=1;ii<=nn;ii++)
    {
        cin>>(a+1)>>(b+1);
        int n=strlen(a+1);
        int wz=0;
        for(int i=1;i<=n;i++)
            if(a[i]!=b[i])
            {
                wz=i;
                break;
            }
        if(!wz) continue;
        id[ii]=wz;
        for(int i=1;i<=n;i++) ha[ii]=ha[ii]*base+a[i];
        for(int i=1;i<=n;i++) ha2[ii]=ha2[ii]*base+b[i];
        len[ii]=n;
    }
    po[0]=1;
    for(int i=1;i<=5000000;i++) po[i]=po[i-1]*base;
    while(q--)
    {
        cin>>(a+1)>>(b+1);
        int n=strlen(a+1),m=strlen(b+1);
        if(n!=m)
        {
            cout<<"0\n";
            continue;
        }
        int wzl=0,wzr=0;
        for(int i=1;i<=n;i++)
            if(a[i]!=b[i])
            {
                wzl=i;
                break;
            }
        for(int i=n;i>=1;i--)
            if(a[i]!=b[i])
            {
                wzr=i;
                break;
            }
        for(int i=1;i<=n;i++) qz[i]=qz[i-1]*base+a[i],qz2[i]=qz2[i-1]*base+b[i];
        int ans=0;
        for(int i=1;i<=nn;i++)
        {
            int x=id[i],y=len[i];
            if(!x) continue;
            if(wzl>=x&&wzl+y-x<=n&&x+wzr-wzl<=y)
            {
                // cout<<"!!!"<<q<<endl;
                int l=wzl-x+1,r=wzl+y-x;
                //cout<<i<<' '<<l<<' '<<r<<' '<<a[l]<<' '<<a[r]<<' '<<suan(l,r).first<<' '<<suan(l,r).second<<endl;
                if(make_pair(ha[i],ha2[i])==suan(l,r))
                {
                    //cout<<i<<' '<<l<<' '<<r<<endl;
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*
4 1
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
*/