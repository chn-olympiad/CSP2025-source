#include<bits/stdc++.h>
using namespace std;
struct staff
{
    long long sa=0,sb=0,sc=0,maxis=0,maxm=0,maxp=0;
}a[100001];
bool cmp(staff x,staff y)
{
    return x.maxp<y.maxp;
}
int main()
{
    cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        long long n,b[3]={0},ans=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i].sa>>a[i].sb>>a[i].sc;
            if(a[i].sa>=a[i].sb&&a[i].sa>=a[i].sc&&a[i].sb>=a[i].sc)
            {
                a[i].maxis=0;
                a[i].maxm=a[i].sa;
                a[i].maxp=a[i].sa-a[i].sb;
            }
            if(a[i].sa>=a[i].sb&&a[i].sa>=a[i].sc&&a[i].sb<a[i].sc)
            {
                a[i].maxis=0;
                a[i].maxm=a[i].sa;
                a[i].maxp=a[i].sa-a[i].sc;
            }
            if(a[i].sa<a[i].sb&&a[i].sa>=a[i].sc)
            {
                a[i].maxis=1;
                a[i].maxm=a[i].sb;
                a[i].maxp=a[i].sb-a[i].sa;
            }
            if(a[i].sa>=a[i].sb&&a[i].sa<a[i].sc)
            {
                a[i].maxis=2;
                a[i].maxm=a[i].sc;
                a[i].maxp=a[i].sc-a[i].sa;
            }
            if(a[i].sa<a[i].sb&&a[i].sa<a[i].sc&&a[i].sb>=a[i].sc)
            {
                a[i].maxis=1;
                a[i].maxm=a[i].sb;
                a[i].maxp=a[i].sb-a[i].sc;
            }
            if(a[i].sa<a[i].sb&&a[i].sa<a[i].sc&&a[i].sb<a[i].sc)
            {
                a[i].maxis=2;
                a[i].maxm=a[i].sc;
                a[i].maxp=a[i].sc-a[i].sb;
            }
            b[a[i].maxis]++;
            ans+=a[i].maxm;
        }
        sort(a,a+n,cmp);
        int q=-1;
        if(b[0]>n/2)
        {
            q=0;
        }
        if(b[1]>n/2)
        {
            q=1;
        }
        if(b[2]>n/2)
        {
            q=2;
        }
        if(q!=-1)
        {
            for(int i=0;b[q]>n/2;i++)
            {
                if(a[i].maxis==q)
                {
                    b[q]--;
                    ans-=a[i].maxp;
                }
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}
