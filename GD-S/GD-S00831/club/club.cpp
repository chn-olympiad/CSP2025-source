#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
int t, n;
int ans;
struct stu1
{
	int a, b, c;
} s[maxn], q1[maxn], q2[maxn], q3[maxn];

int t1, t2, t3; 

bool cmp1(struct stu1& x, struct stu1& obj)
{
	return (x.a-max(x.b, x.c))>(obj.a-max(obj.b, obj.c));
}

bool cmp2(struct stu1& x, struct stu1& obj)
{
	return (x.b-max(x.a, x.c))>(obj.b-max(obj.a, obj.c));
}

bool cmp3(struct stu1& x, struct stu1& obj)
{
	return (x.c-max(x.a, x.b))>(obj.c-max(obj.a, obj.b));
}

void solve()
{
	ans=0;
	t1=t2=t3=0;
	for(int i=0;i<n;++i)
	{
		int x = max(s[i].a, max(s[i].b, s[i].c));
		ans+=x;
		if(x==s[i].a) q1[t1++]=s[i];
		else if(x==s[i].b) q2[t2++]=s[i];
		else if(x==s[i].c) q3[t3++]=s[i];
	}
	if(t1>n/2) {
		int ans1=ans, ans2=ans;
		sort(q1, q1+t1, cmp1);
		for(int i=t1-1;i>=n/2;--i) 
			ans1-=(q1[i].a-max(q1[i].b, q1[i].c));
			
		ans=ans1;
	} else if(t2>n/2) {
		int ans1=ans, ans2=ans;
		sort(q2, q2+t2, cmp2);
		for(int i=t2-1;i>=n/2;--i) 
			ans1-=(q2[i].b-max(q2[i].a, q2[i].c));
		
		ans=ans1;
	} else if(t3>n/2) {
		int ans1=ans, ans2=ans;
		sort(q3, q3+t3, cmp3);
		for(int i=t3-1;i>=n/2;--i) 
			ans1-=(q3[i].c-max(q3[i].a, q3[i].b));
		
		ans=ans1;
	}
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;++i)
		{
			cin>>s[i].a>>s[i].b>>s[i].c;
		}
		solve();
		cout<<ans<<endl; 
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
