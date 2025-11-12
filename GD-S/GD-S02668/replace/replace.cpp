#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int n,q,bca;
int s1_l,s2_l,s1_r,s2_r;
int ans;
struct L
{
	string l1,l2;
	int ca1,l1_l,l2_l,l1_r,l2_r;
}l[MAXN];
string s1,s2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("r","replace.in",stdin);
	freopen("w","replace.out",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i].l1>>l[i].l2;
		string s3=l[i].l1;
		int le=s3.length(),xb,yb;
		for(int j=0;j<le;j++)
		{
			if(l[i].l1[j]=='b')
			{
				xb=j;
			}
			if(l[i].l2[j]=='b')
			{
				yb=j;
			}
			//cout<<1<<" ";
			//cout<<endl;
		}
		
		l[i].ca1=xb-yb;
		l[i].l1_l=xb;
		l[i].l2_l=yb;
		l[i].l1_r=le-xb;
		l[i].l2_r=le-yb;
		//cout<<xb<<" "<<yb<<" "<<le<<endl;
		
	}
	for(int i=1;i<=q;i++)
	{
		cin>>s1>>s2;
		int ls=s1.length(),b1,b2;
		for(int j=0;j<ls;j++)
		{
			if(s1[j]=='b')
			{
				b1=j;
			}
			if(s2[j]=='b')
			{
				b2=j;
			}
		}
		bca=b1-b2;
		s1_l=b1;
		s2_l=b2;
		s1_r=ls-b1;
		s2_r=ls-b2;
		//cout<<s1_l<<" "<<s1_r<<endl;
		for(int j=1;j<=n;j++)
		{
			bool check=false;
			if(l[j].ca1==bca)
			{
				if(s1_l>=l[j].l1_l&&s1_r>=l[j].l1_r)
				{
					//cout<<s1_l<<" "<<l[j].l1_l<<" "<<s1_r<<" "<<l[j].l1_r<<endl;
					check=true;
				}
			}
			if(l[j].ca1==-bca)
			{
				if(s1_l>=l[j].l2_l&&s1_r>=l[j].l2_r)
				{
					//cout<<s1_l<<" "<<l[j].l2_l<<" "<<s1_r<<" "<<l[j].l2_r<<endl;
					check=true;
				}
			}
			if(check)ans++;
			
		}
		cout<<ans<<endl;
	}
	return 0;
}
