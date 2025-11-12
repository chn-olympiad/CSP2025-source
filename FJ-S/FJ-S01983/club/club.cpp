#include<bits/stdc++.h>
using namespace std;
int n,m,c,b[10005],o,p,q,ans=0,l[10005],max1,max2,max3;
struct node{
	int t,v,s;
}a[10005];
int dfs(int u){
	return 0;
}
int cmp(int a1,int a2){
	return a1>a2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m;
		c=m/2;
		ans=0;
		for(int j=1;j<=m;j++)
		{
			cin>>a[j].t>>a[j].v>>a[j].s;
			b[j]=max(a[j].t,max(a[j].v,a[j].s));
			ans=ans+b[j];
			if(b[j]==a[j].t)
				o++;
			else if(b[j]==a[j].v)
				p++;
			else
				q++;
		}
		if(o<=c&&p<=c&&q<=c)
			cout<<ans<<endl;
		else{
			int z=0,x=0,y=0;
			ans=0;
			for(int j=1;j<=m;j++)
			{
				if(a[j].v!=0)
					z=1;
				if(a[j].t!=0)
					x=1;
				if(a[j].s!=0)
					y=1;
			}
			if(z==0&&y==0){
				for(int j=1;j<=m;j++)
					l[j]=a[j].t;
				sort(l+1,l+m+1,cmp);
				for(int j=1;j<=c;j++)
					ans=ans+l[j];
				cout<<ans<<endl;
			}
			else if(z==0&&x==0){
				for(int j=1;j<=m;j++)
					l[j]=a[j].s;
				sort(l+1,l+m+1,cmp);
				for(int j=1;j<=c;j++)
					ans=ans+l[j];
				cout<<ans<<endl;
			}
			else if(x==0&&y==0){
				for(int j=1;j<=m;j++)
					l[j]=a[j].v;
				sort(l+1,l+m+1,cmp);
				for(int j=1;j<=c;j++)
					ans=ans+l[j];
				cout<<ans<<endl;
			}
			else if(x==0){
				for(int j=1;j<=m;j++)
					l[j]=a[j].s;
				sort(l+1,l+m+1,cmp);
				for(int j=1;j<=c;j++)
					ans=ans+l[j];
				for(int j=1;j<=m;j++)
					l[j]=a[j].v;
				sort(l+1,l+m+1,cmp);
				for(int j=1;j<=c;j++)
					ans=ans+l[j];
				cout<<ans<<endl;
			}
			else if(y==0){
				for(int j=1;j<=m;j++)
					l[j]=a[j].t;
				sort(l+1,l+m+1,cmp);
				for(int j=1;j<=c;j++)
					ans=ans+l[j];
				for(int j=1;j<=m;j++)
					l[j]=a[j].v;
				sort(l+1,l+m+1,cmp);
				for(int j=1;j<=c;j++)
					ans=ans+l[j];
				cout<<ans<<endl;
			}
			else if(z==0){
				for(int j=1;j<=m;j++)
					l[j]=a[j].s;
				sort(l+1,l+m+1,cmp);
				for(int j=1;j<=c;j++)
					ans=ans+l[j];
				for(int j=1;j<=m;j++)
					l[j]=a[j].t;
				sort(l+1,l+m+1,cmp);
				for(int j=1;j<=c;j++)
					ans=ans+l[j];
				cout<<ans<<endl;
			}
			else{
				if(m==2){
					for(int j=1;j<=2;j++)
						if(max1<a[j].v)
							max1=a[j].v;
					for(int j=1;j<=2;j++)
						if(max2<a[j].s)
							max2=a[j].s;
					for(int j=1;j<=2;j++)
						if(max3<a[j].t)
							max3=a[j].t;
					if(max(max(max1,max2),max3)==max1)
						ans=max1+max(max2,max3);
					if(max(max(max1,max2),max3)==max2)
						ans=max2+max(max1,max3);
					if(max(max(max1,max2),max3)==max3)
						ans=max3+max(max1,max2);
					cout<<ans;
				}
			}
		}
	}
	return 0;
}

