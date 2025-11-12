#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int f[210][210][210];
struct node
{
	int p,q;
}a[100010],b[100010],c[100010];	
bool cmp(node o,node pp)
{
	return o.p>pp.p;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		bool flag=true;
		int vis1[210]={-1},vis2[210]={-1},vis3[210]={-1};
		int cnt1=1,cnt2=1,cnt3=1;
		cin>>n;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
		{
			int u,v,w;
			cin>>u>>v>>w;
			a[i].p=u;
			b[i].p=v;
			c[i].p=w;
			a[i].q=b[i].q=c[i].q=i;
			if(v!=0||w!=0)
				flag=false;
		}
		if(n==2)
		{
			int mx;
			mx=max(a[1].p+b[2].p,a[1].p+c[2].p);
			mx=max(mx,b[1].p+a[2].p);
			mx=max(mx,b[1].p+c[2].p);
			mx=max(mx,c[1].p+a[2].p);
			mx=max(mx,c[1].p+b[2].p);
			cout<<mx<<endl;
			continue;
		}
		if(flag==true)
		{
			sort(a+1,a+n+1,cmp);
			int cnt=0;
			for(int i=1;i<=n/2;i++)
				cnt+=a[i].p;
			cout<<cnt<<endl;
			continue;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		f[0][0][0]=0;
		f[1][0][0]=a[1].p;
		f[0][1][0]=b[1].p;
		f[0][0][1]=c[1].p;
		int ca=1,cb=1,cc=1;
		int mx=-1;
		for(int i=0;i<=n/2;i++)
		for(int j=0;j<=n/2;j++)
		for(int k=0;k<=n/2;k++)
		{
			if((i==0&&j==0)||(i==0&&k==0)||(j==0&&k==0))
				continue;
			if(i+j+k>n)
				continue;
			/*for(int y=1;y<cnt1;y++)
			while(vis1[y]==a[1].q||vis1[y]==b[1].q||vis1[y]==c[1].q)
			{
				if(vis1[y]==a[1].q)
				{
					a[1].p=-1;
					sort(a+1,a+n+1,cmp);
				}
				if(vis1[y]==b[1].q)
				{
					b[1].p=-1;
					sort(b+1,b+n+1,cmp);
				}
				if(vis1[y]==c[1].q)
				{
					c[1].p=-1;
					sort(c+1,c+n+1,cmp);
				}
			}
			for(int y=1;y<cnt2;y++)
			while(vis2[y]==a[1].q||vis2[y]==b[1].q||vis2[y]==c[1].q)
			{
				if(vis2[y]==a[1].q)
				{
					a[1].p=-1;
					sort(a+1,a+n+1,cmp);
				}
				if(vis2[y]==b[1].q)
				{
					b[1].p=-1;
					sort(b+1,b+n+1,cmp);
				}
				if(vis2[y]==c[1].q)
				{
					c[1].p=-1;
					sort(c+1,c+n+1,cmp);
				}
			}
			for(int y=1;y<cnt3;y++)
			while(vis3[y]==a[1].q||vis3[y]==b[1].q||vis3[y]==c[1].q)
			{
				if(vis3[y]==a[1].q)
				{
					a[1].p=-1;
					sort(a+1,a+n+1,cmp);
				}
				if(vis3[y]==b[1].q)
				{
					b[1].p=-1;
					sort(b+1,b+n+1,cmp);
				}
				if(vis3[y]==c[1].q)
				{
					c[1].p=-1;
					sort(c+1,c+n+1,cmp);
				}
			}
			/*if(f[i-1][j][k]+mxa>max(f[i][j-1][k]+mxb,f[i][j][k-1]+mxc))
			{
				
			}
			if(f[i][j-1][k]+mxb>max(f[i-1][j][k]+mxa,f[i][j][k-1]+mxc))
			{
			}
			if(f[i][j][k-1]+mxc>max(f[i][j-1][k]+mxb,f[i-1][j][k]+mxa))
			{
			}*/
			/*sort(a+1,a+n+1,cmp);
			sort(b+1,b+n+1,cmp);
			sort(c+1,c+n+1,cmp);*/    
			int mxa,mxb,mxc;
			mxa=a[1].p;
			mxb=b[1].p;
			mxc=c[1].p;
			if(i==0)
				f[i][j][k]=max(f[i][j-1][k]+mxb,f[i][j][k-1]+mxc);
			if(j==0)
				f[i][j][k]=max(f[i-1][j][k]+mxa,f[i][j][k-1]+mxc);
			if(k==0)
				f[i][j][k]=max(f[i][j-1][k]+mxb,f[i-1][j][k]+mxa);
			f[i][j][k]=max(f[i-1][j][k]+mxa,max(f[i][j-1][k]+mxb,f[i][j][k-1]+mxc));
			if(mx<f[i][j][k])
				mx=f[i][j][k];
			if(f[i-1][j][k]+mxa>max(f[i][j-1][k]+mxb,f[i][j][k-1]+mxc))
			{
				a[1].p=-1;
				b[a[1].q].p=-1;
				c[a[1].q].p=-1;
				vis1[cnt1]=a[1].q;
				cnt1++;
			}
			if(f[i][j-1][k]+mxb>max(f[i-1][j][k]+mxa,f[i][j][k-1]+mxc))
			{
				b[1].p=-1;
				a[b[1].q].p=-1;
				c[b[1].q].p=-1;
				vis2[cnt2]=b[1].q;
				cnt2++;
			}
			if(f[i][j][k-1]+mxc>max(f[i][j-1][k]+mxb,f[i-1][j][k]+mxa))
			{
				c[1].p=-1;
				b[c[1].q].p=-1;
				a[c[1].q].p=-1;
				vis3[cnt3]=c[1].q;
				cnt3++;
			}
			sort(a+1,a+n+1,cmp);
			sort(b+1,b+n+1,cmp);
			sort(c+1,c+n+1,cmp);
		}
		/*for(int i=0;i<=n/2;i++)
		for(int j=0;j<=n/2;j++)
		for(int k=0;k<=n/2;k++)
			cout<<"f["<<i<<"]["<<j<<"]["<<k<<"]="<<f[i][j][k]<<endl;*/
		cout<<mx<<endl;
	}
	return 0;
}
