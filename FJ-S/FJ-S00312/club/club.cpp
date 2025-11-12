#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a,b,c;
	int change;
}num[114514];
vector<int> ap;
vector<int> bp;
vector<int> cp;
//clubs
int max__(int a,int b)
{
	return (a>b?a:b);
}
bool cmp(int a1,int b1)
{
	return num[a1].change>num[b1].change;
}
inline int getchange(int a1,int b1,int c1)
{
	if(a1<b1)swap(a1,b1);
	if(b1<c1)swap(b1,c1);
	if(a1<b1)swap(a1,b1);
	return a1-b1;
}
//lowest miss
int ans;
inline int getans(int a1,int b1,int c1)
{
	return max__(a1,max__(b1,c1));
}//lazy
int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	cout.tie(0);
 	freopen("club.in","r",stdin);
 	freopen("club.out","w",stdout);
 	int t;
 	cin >> t;
 	while(t--)
 	{
 		int n;
 		cin >> n;
 		//input n
 	for(int i = 1;i<=n;i++)
 	{
 		
 		cin >> num[i].a >> num[i].b >> num[i].c;
		num[i].change=getchange(num[i].a,num[i].b,num[i].c);
		ans+=getans(num[i].a,num[i].b,num[i].c);
		int mx = max__(a,max__(b,c));
		if(mx==a)ap.insert(lower_bound(ap.begin(),ap.end(),i,cmp),i);
		else if(mx==b)bp.insert(lower_bound(bp.begin(),bp.end(),i,cmp),i);
		else if(mx==c)cp.insert(lower_bound(cp.begin(),cp.end(),i,cmp),i);
	}
	//input a[i];
	if(ap.size()>(n/2))
	{
		for(int i = ap.size()-1;i>=n/2;i--)
		{
			ans-=num[ap[i]].change;
		}
	}
	if(bp.size()>(n/2))
	{
		for(int i = bp.size()-1;i>=n/2;i--)
		{
			ans-=num[bp[i]].change;
		}
	}
	if(cp.size()>(n/2))
	{
		for(int i = cp.size()-1;i>=n/2;i--)
		{
			ans-=num[cp[i]].change;
		}
	}
	//more kick
	cout << ans << '\n';
	ap.clear();
	bp.clear();
	cp.clear();
	ans=0;
 }
 return 0;
}
