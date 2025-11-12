#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N],c[N],sum=0,fz1[N],fz2[N],fz3[N],q=0,w=0,e=0,zz[N];
int t,n;
int main()
{
	freopen("club.in","r",stdin);//aaaaaaaaaaaaaaaaaaaa
	freopen("club.out","w",stdout);
	//记得删除 
	cin>>t;
	while(t--)
	{
		cin>>n;//每轮要清空 
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			sum+=max(a[i],max(b[i],c[i]));
			int da=max(a[i],max(b[i],c[i]));
			//cout<<da;
////			if(a[i]==da)cout<<1;
////			else cout<<2;
			if(a[i]==da)q++,fz1[q]=i;
			else if(b[i]==da)w++,fz2[w]=i;
			else if(c[i]==da)e++,fz3[e]=i;
		}
		//cout<<q<<w<<e<<endl;
		if(q>(n/2))
		{
			//cout<<1<<endl<<endl;
			int r=q-(n/2);
			for(int i=1;i<=q;i++)
			{
				zz[i]=a[fz1[i]]-max(b[fz1[i]],c[fz1[i]]);
			}
			sort(zz+1,zz+q+1);
			for(int i=1;i<=r;i++)
			{
				sum-=zz[i];
			}
		}
		else if(w>(n/2))
		{
			//cout<<2<<endl<<endl;
			int r=w-(n/2);
			for(int i=1;i<=w;i++)
			{
				zz[i]=b[fz2[i]]-max(a[fz2[i]],c[fz2[i]]);
			}
			sort(zz+1,zz+w+1);
			for(int i=1;i<=r;i++)
			{
				sum-=zz[i];
			}
		}
		else if(e>(n/2))
		{
			int r=e-(n/2);
			for(int i=1;i<=e;i++)
			{
				zz[i]=c[fz3[i]]-max(a[fz3[i]],b[fz3[i]]);
			}
			sort(zz+1,zz+e+1);
			for(int i=1;i<=r;i++)
			{
				sum-=zz[i];
			}
		}
		cout<<sum<<endl;
		sum=0;q=0,w=0,e=0;
		sizeof(a,0,sizeof(a));
		sizeof(b,0,sizeof(b));
		sizeof(c,0,sizeof(c));
		sizeof(zz,0,sizeof(zz));
	}
	return 0;
}
