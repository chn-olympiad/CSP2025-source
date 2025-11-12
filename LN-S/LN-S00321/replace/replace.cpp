#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
#define mo1 1000000007
#define mo2 998244353
#define ll long long
#define M 5000005
char a[M],b[M];
map<pair<ll,ll>,pair<ll,ll>>ma;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q,fl=0;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%s%s",a,b);
        int la=strlen(a),lb=strlen(b);
        ll h11=0,h12=0,h21=0,h22=0;
        int lr=0;
        int rr=la;
        while(a[lr]==b[lr])lr++;
        while(a[rr]==b[rr])rr--;
        for(int j=lr;j<=rr;j++)h11=(h11*26+a[j])%mo1;
        for(int j=lr;j<=rr;j++)h21=(h21*26+a[j])%mo2;
        for(int j=lr;j<=rr;j++)h12=(h12*26+b[j])%mo1;
        for(int j=lr;j<=rr;j++)h22=(h22*26+b[j])%mo2;
        ma[make_pair(h11,h21)]=make_pair(h21,h22);
        //printf("%lld %lld\n",ma[make_pair(h11,h21)].first,h21);
        //for(int j=0;j<la;j++)if(a[j]!='a'||a[j]!='b')fl=1;
        //for(int j=0;j<lb;j++)if(b[j]!='a'||b[j]!='b')fl=1;
    }for(int i=n+1;i<=q+n;i++)
    {
        scanf("%s%s",a,b);
        int ans=0;
        int la=strlen(a),lb=strlen(b);
        if(la!=lb){printf("0\n");continue;}
        int lr=0;
        int rr=la;
        ll h11=0,h12=0,h21=0,h22=0;
        while(a[lr]==b[lr])lr++;
        while(a[rr]==b[rr])rr--;
        for(int j=lr;j<=rr;j++)h11=(h11*26+a[j])%mo1;
        for(int j=lr;j<=rr;j++)h21=(h21*26+a[j])%mo2;
        for(int j=lr;j<=rr;j++)h12=(h12*26+b[j])%mo1;
        for(int j=lr;j<=rr;j++)h22=(h22*26+b[j])%mo2;
        if(ma[make_pair(h11,h21)]==make_pair(h12,h22))ans++;
        /*for(int j=0;j<la;j++)
        {
            if(a[j]!=b[j])
            {
                ll op11=0,op21=0,op12=0,op22=0;
                while(a[j]!=b[j]){
                    op11=(op11*26+a[j])%mo1;
                    op21=(op21*26+a[j])%mo2;
                    op12=(op12*26+a[j])%mo1;
                    op22=(op22*26+a[j])%mo2;
                    j++;
                }//printf("%lld %lld %lld %lld\n",op11,op21,ma[make_pair(op11,op21)].first,op21);
                if(ma[make_pair(op11,op21)]==make_pair(op12,op22))ans++;
            }
        }*/printf("%d\n",ans);
        printf("%lld %lld %lld %lld\n",h11,h21,ma[make_pair(h11,h21)].first,h21);
        //for(int j=0;j<la;j++)if(a[j]!='a'||a[j]!='b')fl=1;
        //for(int j=0;j<lb;j++)if(b[j]!='a'||b[j]!='b')fl=1;
    }
}