#include<bits/stdc++.h>
using namespace std;
long long t,n,s1,s2,s3;
struct f{
	int a,b,c,maxx,s;
}x[100005];
bool cmp1(f x,f y)
{
	if(x.a!=y.a) return x.a>y.a;
	else if(x.b!=y.b) return x.b>y.b;
	return x.c>y.c;
}
bool cmp2(f x,f y)
{
	if(x.b!=y.b) return x.b>y.b;
	else if(x.a!=y.a) return x.a>y.a;
	return x.c>y.c;
}
bool cmp3(f x,f y)
{
	if(x.c!=y.c) return x.c>y.c;
	else if(x.a!=y.a) return x.a>y.a;
	return x.c>y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		s1=s2=s3=0;
		for(int i=1;i<=n;i++) cin>>x[i].a>>x[i].b>>x[i].c;
		sort(x+1,x+1+n,cmp1);
		for(int i=1;i<=n/2;i++) s1+=x[i].a;
		for(int i=n/2+1;i<=n;i++) s1+=max(x[i].b,x[i].c);
		sort(x+1,x+1+n,cmp2);
		for(int i=1;i<=n/2;i++) s2+=x[i].b;
		for(int i=n/2+1;i<=n;i++) s2+=max(x[i].a,x[i].c);
		sort(x+1,x+1+n,cmp3);
		for(int i=1;i<=n/2;i++) s3+=x[i].c;
		for(int i=n/2+1;i<=n;i++) s3+=max(x[i].a,x[i].b);
		cout<<max(max(s1,s2),s3)<<"\n";
	}
	return 0;
}
