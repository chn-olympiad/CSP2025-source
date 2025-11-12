#include<bits/stdc++.h>
using namespace std;
int T,n,num1,num2,num3,cnt1,cnt2,cnt3;
long long ans;
bool fl[100010];
struct node
{
	int f,s,t;
}a[100010];
struct node2
{
	int w,pos;
}q1[100010],q2[100010],q3[100010],s1[100010],s2[100010],s3[100010];
bool cmp(node2 b,node2 c){return b.w>c.w;}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while (T--)
	{
		cin>>n;
		for (int i=1;i<=n;i++) fl[i]=0;
		num1=0,num2=0,num3=0,ans=0,cnt1=0,cnt2=0,cnt3=0;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i].f>>a[i].s>>a[i].t;
			int mx=max({a[i].f,a[i].s,a[i].t});
			if (mx==a[i].f) num1++,q1[num1]={a[i].f,i};
			else if (mx==a[i].s) num2++,q2[num2]={a[i].s,i};
				else if (mx==a[i].t) num3++,q3[num3]={a[i].t,i};
			ans+=mx;
		}
		if (num1<=n/2 && num2<=n/2 && num3<=n/2){cout<<ans<<endl;continue;}
		sort(q1+1,q1+num1+1,cmp),sort(q2+1,q2+num2+1,cmp),sort(q3+1,q3+num3+1,cmp);
		if (num1>n/2)
		{
			while (num1>n/2)
			{
				cnt2++,s2[cnt2]={a[q1[num1].pos].s,q1[num1].pos};
				cnt3++,s3[cnt3]={a[q1[num1].pos].t,q1[num1].pos};
				num1--;
			}
			sort(s2+1,s2+cnt2+1,cmp),sort(s3+1,s3+cnt3+1,cmp);
			int i=1,j=1,cnt=0,ok=cnt2;
			while (cnt<ok)
			{
				if (s2[i].w>=s3[j].w && cnt2<n/2)
				{
					fl[s2[i].pos]=1;
					ans=ans-a[s2[i].pos].f+s2[i].w;
					cnt2++,i++,cnt++;
				}
				else
				{
					fl[s3[j].pos]=1;
					ans=ans-a[s3[j].pos].f+s3[j].w;
					cnt3++,j++,cnt++;
				}
				while (fl[s2[i].pos]) i++;
				while (fl[s3[j].pos]) j++;
			}
			cout<<ans;
		}
		if (num2>n/2)
		{
			while (num2>n/2)
			{
				cnt1++,s1[cnt1]={a[q2[num2].pos].f,q2[num2].pos};
				cnt3++,s3[cnt3]={a[q2[num2].pos].t,q2[num2].pos};
				num2--;
			}
			sort(s1+1,s1+cnt1+1,cmp),sort(s3+1,s3+cnt3+1,cmp);
			int i=1,j=1,cnt=0,ok=cnt1;
			while (cnt<ok)
			{
				if (s1[i].w>=s3[j].w && cnt1<n/2)
				{
					fl[s1[i].pos]=1;
					ans=ans-a[s1[i].pos].s+s1[i].w;
					cnt1++,i++,cnt++;
				}
				else
				{
					fl[s3[j].pos]=1;
					ans=ans-a[s3[j].pos].s+s3[j].w;
					cnt3++,j++,cnt++;
				}
				while (fl[s1[i].pos]) i++;
				while (fl[s3[j].pos]) j++;
			}
			cout<<ans;
		}
		if (num3>n/2)
		{
			while (num3>n/2)
			{
				cnt2++,s2[cnt2]={a[q3[num3].pos].s,q3[num3].pos};
				cnt1++,s1[cnt1]={a[q3[num3].pos].f,q3[num3].pos};
				num3--;
			}
			sort(s2+1,s2+cnt2+1,cmp),sort(s1+1,s1+cnt1+1,cmp);
			int i=1,j=1,cnt=0,ok=cnt1;
			while (cnt<ok)
			{
				if (s2[i].w>=s1[j].w && cnt2<n/2)
				{
					fl[s2[i].pos]=1;
					ans=ans-a[s2[i].pos].t+s2[i].w;
					cnt2++,i++,cnt++;
				}
				else
				{
					fl[s1[j].pos]=1;
					ans=ans-a[s1[j].pos].t+s1[j].w;
					cnt1++,j++,cnt++;
				}
				while (fl[s2[i].pos]) i++;
				while (fl[s1[j].pos]) j++;
			}
			cout<<ans;
		}
		cout<<endl;
	}	
	return 0;
} 
