#include <bits/stdc++.h>
using namespace std;
int T;
struct node {
	int zhi,id;
	int ab,bc,ac;
}a1[100005],b1[100005],c1[100005];
bool cmp1(node x,node y)
{
	if(max(x.ab,x.ac)>max(y.ab,y.ac)) return 0;
	else return 1;
}
bool cmp2(node x,node y)
{
	if(max(x.ab,x.bc)>max(y.ab,y.bc)) return 0;
	else return 1;
}
bool cmp3(node x,node y)
{
	if(max(x.ac,x.bc)>max(y.ac,y.bc)) return 0;
	else return 1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		int n,a[100005],b[100005],c[100005];
		int id1=0,id2=0,id3=0,sum=0,aa=0,bb=0,cc=0;
		memset(a1,0,sizeof a1);
		memset(b1,0,sizeof b1);
		memset(c1,0,sizeof c1);
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]) id1++,a1[id1].zhi=a[i],a1[id1].id=i,a1[id1].ab=a[i]-b[i],a1[id1].ac=a[i]-c[i];
			else if(b[i]>=a[i]&&b[i]>c[i]) id2++,b1[id2].zhi=b[i],b1[id2].id=i,b1[id2].ab=b[i]-a[i],b1[id2].bc=b[i]-c[i];
			else id3++,c1[id3].zhi=c[i],c1[id3].id=i,b1[id2].ac=abs(a[i]-c[i]),b1[id2].bc=abs(b[i]-c[i]);
		}
		
		sort(a1+1,a1+1+id1,cmp1);
		if(id1>n/2)
		{
			for(int i=1;i<=id1-n/2;i++) 
			{
				aa++;
				if(b[a1[i].id]>c[a1[i].id])
				{
					if(id2+1<=n/2) id2++,b1[id2].zhi=b[a1[i].id],b1[id2].id=a1[i].id;
					else id3++,c1[id3].zhi=c[a1[i].id],c1[id3].id=a1[i].id;
				}
				else
				{
					if(id3+1<=n/2) id3++,c1[id3].zhi=c[a1[i].id],c1[id3].id=i;
					else id2++,b1[id2].zhi=b[a1[i].id],b1[id2].id=i;
				}
			}
		}
		sort(b1+1,b1+1+id2,cmp2);
		if(id2>n/2)
		{
			for(int i=1;i<=id2-n/2;i++) 
			{
				bb++;
				if(a[b1[i].id]>c[b1[i].id])
				{
					if(id1+1<=n/2) id1++,a1[id1].zhi=a[b1[i].id],a1[id1].id=b1[i].id;
					else id3++,c1[id3].zhi=c[b1[i].id],c1[id3].id=b1[i].id;
				}
				else
				{
					if(id3+1<=n/2) id3++,c1[id3].zhi=c[b1[i].id],c1[id3].id=b1[i].id;
					else id1++,a1[id1].zhi=a[b1[i].id],a1[id1].id=b1[i].id;
				}
			}
		}
		sort(c1+1,c1+1+id3,cmp3);
		if(id3>n/2)
		{
			for(int i=1;i<=id3-n/2;i++) 
			{ cc++;
				if(b[c1[i].id]>a[c1[i].id])
				{
					if(id2+1<=n/2) id2++,b1[id2].zhi=b[c1[i].id],b1[id2].id=c1[i].id;
					else id1++,a1[id1].zhi=a[c1[i].id],a1[id1].id=c1[i].id;
				}
				else
				{
					if(id1+1<=n/2) id1++,a1[id1].zhi=a[c1[i].zhi],a1[id1].id=c1[i].id;
					else id2++,b1[id2].zhi=b[c1[i].zhi],b1[id2].id=c1[i].id;
				}
			}
		}
		for(int i=id1;i>aa;i--) sum+=a[a1[i].id];
		for(int i=id2;i>bb;i--) sum+=b[b1[i].id];
		for(int i=id3;i>cc;i--) sum+=c[c1[i].id]; 
		cout<<sum<<endl;
		
	}
	return 0;
} 
