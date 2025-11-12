#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t,n;
int cs[100005];
struct node
{
    int d[5];
}a[100005];
struct nod
{
    int x,y;
};
bool cmp3(nod a,nod b)
{
    return a.y>b.y;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin >> t;
	while(t)
	{
		t--;
		cin >> n;
		int k1=0,k2=0;
		for(int i=1;i<=n;i++) cin >> a[i].d[1] >> a[i].d[2] >> a[i].d[3];
        int f=0,s=0,h=0;
        for(int i=1;i<=n;i++)//first choose
        {
            int mx=max(max(a[i].d[1],a[i].d[2]),a[i].d[3]);
            if(mx==a[i].d[1])
            {
                cs[i]=1;
                f++;
            }
            else if(mx==a[i].d[2])
            {
                cs[i]=2;
                s++;
            }
            else if(mx==a[i].d[3])
            {
                cs[i]=3;
                h++;
            }
        }
        if( (f<=n/2 and s<=n/2) and h<=n/2 ) int u;//no fight
        else
        {
            int k;
            if(f>n/2) k=1;
            else if(s>n/2) k=2;
            else if(h>n/2) k=3;
            vector<nod> lt;
            int nx1=k%3+1,nx2=nx1%3+1;
            for(int i=1;i<=n;i++)
            {
                if(cs[i]!=k) continue;
                lt.push_back( {i,min(a[i].d[k]-a[i].d[nx1],a[i].d[k]-a[i].d[nx2])} );
            }
            sort(lt.begin(),lt.end(),cmp3);
            for(int i=0;i<lt.size();i++)
            {
                if(i<=n/2-1) continue;
                if(a[lt[i].x].d[nx1]>a[lt[i].x].d[nx2]) cs[lt[i].x]=nx1;
                else cs[lt[i].x]=nx2;
            }
        }
        ll sum=0;
        for(int i=1;i<=n;i++) sum+=a[i].d[cs[i]];
        cout << sum << endl;
    }
	return 0;
}
