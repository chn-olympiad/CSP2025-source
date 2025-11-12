#include<bits/stdc++.h>
using namespace std;
int fa[100005],fb[100005],fc[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,n;
	cin>>T;
	while(T--)
	{
		int ca=0,cb=0,cc=0;
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			int ta=a,tb=b,tc=c;
			if(a<b) swap(a,b);
			if(a<c) swap(a,c);
			if(b<c) swap(b,c);
			ans+=a;
			if(ta>tb&&ta>tc) fa[++ca]=a-b;
			else if(tb>ta&&tb>tc) fb[++cb]=a-b;
			else fc[++cc]=a-b; 
		}
		if(ca*2>n)
		{
			sort(fa+1,fa+ca+1);
			for(int i=1;i<=(ca*2-n)/2;i++) ans-=fa[i];
		}
		else if(cb*2>n)
		{
			sort(fb+1,fb+cb+1);
			for(int i=1;i<=(cb*2-n)/2;i++) ans-=fb[i];
		}
		else if(cc*2>n)
		{
			sort(fc+1,fc+cc+1);
			for(int i=1;i<=(cc*2-n)/2;i++) ans-=fc[i];
		}
		cout<<ans<<'\n';
	}
}
