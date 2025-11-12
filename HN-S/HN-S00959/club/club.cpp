#include<bits/stdc++.h>
using namespace std;
struct memble{
	int A,B,C,id;
	bool f;
};
bool com1(memble a,memble b)
{
	return a.A > b.A ;
}
bool com2(memble a,memble b)
{
	return a.B > b.B ;
}
bool com3(memble a,memble b)
{
	return a.C > b.C ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int xx=1;xx<=t;++xx)
	{
		int n,k1=0,k2=0,k3=0,ans=0,ans2=0,ans3=0,ans1=0;
		cin>>n;
		memble a[n+1],b[n+1],c[n+1];
	
		for(int i=1;i<=n;++i)
		{
			cin>>a[i].A>>a[i].B>>a[i].C;
			a[i].id =i,a[i].f =0;
			b[i]=a[i];
			c[i]=a[i];
		}
		int mid=n/2;
		sort(a+1,a+1+n,com1);
		sort(b+1,b+1+n,com2);
		sort(c+1,c+1+n,com3);
		if(n==2)
		{
			for(int i=1;i<=3;++i)
			{
				if(i==1)
				{
					ans=max(max(ans,a[1].A+a[2].C),a[1].A+a[2].B);
				}
				if(i==2)
				{
					ans=max(max(ans,a[1].B+a[2].C),a[1].B+a[2].A);
				}
				if(i==3)
				{
					ans=max(max(ans,a[1].C+a[2].A),a[1].C+a[2].B);
				}
			}
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;++i)
		{
			if(a[i].A >=a[i].B &&a[i].A >=a[i].C &&a[i].f!=1)
			{
				if(k1<mid)
				{
				k1++;
				ans+=a[i].A;
				for(int h=1;h<=n;++h)
				{ 
				  if(a[i].id==b[i].id)	
				  b[h].f=a[i].f=1; 
				  if(a[i].id==c[i].id)
				  c[h].f=a[i].f=1;
				}
				}
			}
			if(b[i].B >=b[i].A&& b[i].B >=b[i].C&&b[i].f!=1)
			{
				if(k2<mid)
				{
					k2++;
					ans+=b[i].B;
				for(int h=1;h<=n;++h)
				{
					if(c[i].id==b[i].id)	
				  b[h].f=c[i].f=1; 
				  if(a[i].id==b[i].id)
				  b[h].f=a[i].f=1;
				}
				}
					
			}
			if(c[i].C >=c[i].A&&c[i].C >=c[i].B&&c[i].f!=1 )
			{
				if(k3<mid)
				{
					k3++;
					ans+=c[i].C ;
					for(int h=1;h<=n;++h)
				{ 
			
					if(c[i].id==b[i].id)	
				  b[h].f=c[i].f=1; 
				  if(a[i].id==c[i].id)
				  c[h].f=a[i].f=1;
				}
				  
				}
			}
			
		}
        cout<<ans<<endl;
}
		fclose(stdin);
	fclose(stdout);
	return 0;

}

