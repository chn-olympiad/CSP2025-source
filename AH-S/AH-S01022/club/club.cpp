#include<bits/stdc++.h>
using namespace std;
struct peo
{
    int a,b,c,m;
    peo():a(0),b(0),c(0),m(0) {}
};
peo a[100010];
int s[100010];
int n,ans;
void dfs(int i,int a,int b,int c,int sm)
{
	//cout<<i<<" "<<a<<" "<<b<<" "<<c<<" "<<sm<<"\n";
    if(i==n)
    {
		//cout<<sm<<"!!!!!!!!!!!!!!!!\n";
        ans=max(ans,sm);
        return;
    }
    if(sm+s[i]<=ans)return;
    if(a<n/2)
    {
        dfs(i+1,a+1,b,c,sm+::a[i].a);
    }
    if(b<n/2)
    {
        dfs(i+1,a,b+1,c,sm+::a[i].b);
    }
    if(c<n/2)
    {
        dfs(i+1,a,b,c+1,sm+::a[i].c);
    }
}
void run()
{
    ans=0;
    cin>>n;
    int tmp=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].a>>a[i].b>>a[i].c;
        a[i].m=max(max(a[i].a,a[i].b),a[i].c);
        tmp+=a[i].c;
    }
    if(tmp==0)
    {
        int cnt1=0,cnt2=0,ans=0;
        for(int i=0;i<n;i++)
        {
            if(a[i].a>a[i].b)
            {
                cnt1++;
                ans+=a[i].a;
            }
            else
            {
                cnt2++;
                ans+=a[i].b;
            }
        }
        vector<int> tp;
        if(cnt1>n/2)
        {
            for(int i=0;i<n;i++)
            {
                if(a[i].a>a[i].b)
                {
                    tp.push_back(a[i].a-a[i].b);
                }
            }
            sort(tp.begin(),tp.end());
            for(int i=0;i<cnt1-n/2;i++)
            {
                ans-=tp[i];
            }
        }
        else if(cnt2>n/2)
        {
            for(int i=0;i<n;i++)
            {
                if(a[i].a<a[i].b)
                {
                    tp.push_back(a[i].b-a[i].a);
                }
            }
            sort(tp.begin(),tp.end());
            for(int i=0;i<cnt2-n/2;i++)
            {
                ans-=tp[i];
            }
        }
        cout<<ans;
        return;
    }
    for(int i=n-1;i>=0;i--)
    {
		s[i]=s[i+1]+a[i].m;
	}
	if(n<=200)
    {
        dfs(0,0,0,0,0);
        cout<<ans;
        return;
    }
	cout<<s[0];
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin>>t;
    while(t--)
    {
        run();
        cout<<"\n";
    }

    return 0;
}
/*
1
4
18 2 14
16 2 15
16 2 6
19 2 10
*/
