#include<bits/stdc++.h>
using namespace std;

int a[100005],b[100005],c[100005],n;
struct node
{
	int val,w;
}ma[100005],mb[100005],mc[100005];
bool cmp(node x,node y)
{
	return x.w<y.w;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(int i=1;i<=100000;i++){
			ma[i]=mb[i]=mc[i]={0,0};
		}
		int cnta=0,cntb=0,cntc=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			int mx,md;
			int x=max(a[i],b[i]);
			int y=max(b[i],c[i]);
			int z=max(c[i],a[i]);
			mx=max(a[i],max(b[i],c[i]));
			md=min(x,min(y,z));
		//	cout<<mx<<" "<<md<<endl;
			if(mx==a[i]){
				cnta++;
				ma[cnta].val=mx;
			//	ma[cnta].id=i;
				ma[cnta].w=mx-md;
			}else if(mx==b[i]){
				cntb++;
				mb[cntb].val=mx;
			//	mb[cntb].id=i;
				mb[cntb].w=mx-md;
			}else{
				cntc++;
				mc[cntc].val=mx;
			//	mc[cntc].id=i;
				mc[cntc].w=mx-md;
			}
		}
		int k=n/2;
		long long ans=0;
		for(int i=1;i<=cnta;i++)	ans+=ma[i].val;
		for(int i=1;i<=cntb;i++)	ans+=mb[i].val;
		for(int i=1;i<=cntc;i++)	ans+=mc[i].val;
		if(cnta<=k&&cntb<=k&&cntc<=k){
			cout<<ans<<endl;
		}else{
			int mx=max(cnta,max(cntb,cntc));
			if(mx==cnta){
				sort(ma+1,ma+cnta+1,cmp);
				for(int i=1;i<=k;i++)	ans-=ma[i].w;
			}else if(mx==cntb){
				sort(mb+1,mb+cntb+1,cmp);
				for(int i=1;i<=k;i++)	ans-=mb[i].w;
			}else{
				sort(mc+1,mc+cntc+1,cmp);
				for(int i=1;i<=k;i++)	ans-=mc[i].w;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
