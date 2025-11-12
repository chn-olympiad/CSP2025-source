#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
long long t,n,vis[MAXN],ans,bs,cnt,mx,d[MAXN],sum;
struct node{
	long long name,h;
}a[MAXN],b[MAXN],c[MAXN];
bool cmp(node a,node b)
{
	if(a.h!=b.h)return a.h>b.h;
	else return a.name<b.name;
}
int main()
{
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>t;
while(t--)
{
	ans=0,bs=0,cnt=0,sum=0;
	cin>>n;
	mx=n/2;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].h>>b[i].h>>c[i].h;
		vis[i]=0;
		d[i]=0;
		a[i].name=i;
		b[i].name=i;
		c[i].name=i;
	}
	sort(1+a,1+a+n,cmp);
	sort(1+b,1+b+n,cmp);
	sort(1+c,1+c+n,cmp);
	if(n==2)
	{
		long long x1,x2,x3,x4,x5,x6;
		x1=a[1].h+b[2].h;
		x2=a[1].h+c[2].h;
		x3=b[1].h+a[2].h;
		x4=b[1].h+c[2].h;
		x5=c[1].h+b[2].h;
		x6=c[1].h+a[2].h;
		sum=max(x1,max(x2,max(x3,max(x4,max(x5,x6)))));
		cout<<sum<<endl;
		continue;
	}
    for(int i=1;i<=n;i++)
    {
		//1
		if(ans<mx){
			long long w=a[i].h,q=a[i].name;
			if(vis[q]==0) {
				ans++;
				sum+=w;
				d[q]=w;
				vis[q]=1;
			}
			else {
				if(w>d[q]){
					ans++;
					sum+=w-d[q];
					d[q]=w;
					if(vis[q]==1) ans--;
					if(vis[q]==2) bs--;
					if(vis[q]==3) cnt--;
					vis[q]=1;
				}}} 
				//2
				if(bs<mx){
			long long w=b[i].h,q=b[i].name;
			if(vis[q]==0) {
				bs++;
				sum+=w;
				d[q]=w;
				vis[q]=2;
			}
			else {
				if(w>d[q]){
					bs++;
					sum+=w-d[q];
					d[q]=w;
					if(vis[q]==1) ans--;
					if(vis[q]==2) bs--;
					if(vis[q]==3) cnt--;
					vis[q]=2;
				}}} 
				//3
				if(cnt<mx){
			long long w=c[i].h,q=c[i].name;
			if(vis[q]==0) {
				cnt++;
				sum+=w;
				d[q]=w;
				vis[q]=3;
			}
			else {
				if(w>d[q]){
					cnt++;
					sum+=w-d[q];
					d[q]=w;
					if(vis[q]==1) ans--;
					if(vis[q]==2) bs--;
					if(vis[q]==3) cnt--;
					vis[q]=3;
				}}} 
				
	}


cout<<sum<<endl;
}
return 0;
}
