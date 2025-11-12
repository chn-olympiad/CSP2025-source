#include <iostream>
#include <algorithm>
using namespace std;
long long mod=1e9+7,h=5081,mod2=1e9+9;
int n,q,len[200010],sum,zf[200010];
long long hx1[200010],hx2[200010],hxs[200010],hxt[200010],p[200010];
long long hy1[200010],hy2[200010],hys[200010],hyt[200010];
void work1()
{
    while(q--)
    {
        string s,t;
        cin >> s >> t;
        int lens=s.size(),lent=t.size();
        s=" "+s;
        t=" "+t;
        if(lens!=lent)
        {
            cout << "0" << endl;
            continue;
        }
        for(int i=1;i<=lens;i++)
        {
            hxs[i]=(hxs[i-1]*h+s[i])%mod;
            hxt[i]=(hxt[i-1]*h+t[i])%mod;
            hys[i]=(hys[i-1]*h+s[i])%mod2;
            hyt[i]=(hyt[i-1]*h+t[i])%mod2;
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j+len[i]-1<=lens;j++)
            {
                int x=j-1,y=len[i],z=lens-(j+len[i]-1);
                long long th=((hxs[x+y]-p[y]*hxs[x])%mod+mod)%mod;
                long long thz=((hxt[x+y]-p[y]*hxt[x])%mod+mod)%mod;
                long long th1=((hys[x+y]-p[y]*hys[x])%mod2+mod2)%mod2;
                long long thz1=((hyt[x+y]-p[y]*hyt[x])%mod2+mod2)%mod2;
                //cout << x << " " << y << " " << z << endl;
                //cout << th << " " << thz << endl;
                if(th!=hx1[i])  continue;
                if(thz!=hx2[i]) continue;
                if(th1!=hy1[i])  continue;
                if(thz1!=hy2[i]) continue;
                long long d1=((hxs[lens]-p[z]*th+p[z]*thz)%mod+mod)%mod;
                long long d2=((hys[lens]-p[z]*th1+p[z]*thz1)%mod2+mod2)%mod2;
                if(d1!=hxt[lens])   continue;
                if(d2!=hyt[lens])   continue;
                cnt++;
            }
        }
        for(int i=1;i<=lens;i++)    hxs[i]=hxt[i]=hys[i]=hyt[i]=0;
        cout << cnt << endl;
    }
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    p[0]=1;
    for(int i=1;i<=200000;i++)
    {
        p[i]=(p[i-1]*h)%mod;
    }
    for(int i=1;i<=n;i++)
    {
        string s1,s2;
        cin >> s1 >> s2;
        len[i]=s1.size();
        sum+=len[i]*2;
        long long now1=0,now2=0,now3=0,now4=0;
        int b1=0,b2=0;
        for(int j=0;j<s1.size();j++)
        {
            now1=now1*h+s1[j];
            now1%=mod;
            now2=now2*h+s2[j];
            now2%=mod;
            now3=now3*h+s1[j];
            now3%=mod2;
            now4=now4*h+s2[j];
            now4%=mod2;
            if(s1[i]=='b')  b1=i;
            if(s2[i]=='b')  b2=i;
            //cout << now1 << " " << now2 << endl;
        }
        zf[i]=b1-b2;
        hx1[i]=now1;
        hx2[i]=now2;
        hy1[i]=now3;
        hy2[i]=now4;
        //cout << hx1[i] << " " << hx2[i] << endl;
    }
    if(sum<=2000)
    {
        work1();
        return 0;
    }
    /*while(q--)
    {
        string s,t;
        cin >> s >> t;
        int lens=s.size(),lent=t.size();
        s=" "+s;
        t=" "+t;
        if(lens!=lent)
        {
            cout << "0" << endl;
            return 0;
        }
        int sb=0,tb=0;
        for(int i=1;i<=lens;i++)
        {
            if(s[i]=='b')   sb=i;
            if(t[i]=='b')   tb=i;
        }
        int b=0;
    }*/
    return 0;
}
