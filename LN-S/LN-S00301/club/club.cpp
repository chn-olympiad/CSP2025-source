#include<bits/stdc++.h>
using namepspace std;
int n,T;
struct mn{
	int i1,i2,i3,m1,m2,m3;
}c[100100];
struct n1{
	int id,k;
}y[11]
int a[100100][4];
bool cmp(mn a,nn b){
	if(a.i1=b.i1){
		return a.m1>b,m1;	
	}else{
		return a.i1<b,i1;
	}
}
int a[100100][4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(i=1;i<=n;i++){
			int y[11];
			for(int j=1;j<=3;j++){
				cin>>y[j].k;
				cin>>a[i][j];
				u=max(u,a[i][j]);
			}
			sort(y+1,y+4,cm);
			c[i].id=1;
			c[i].m1=y[1].k,c[i].i1=y[1].id;
			c[i].m2=y[2].k,c[i].i2=y[2].id;
			c[i].m3=y[3].k,c[i].i3=y[3].id;
		}
		sort(c+1,c+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			cout<<c[i].i1<<" "<<c[i].m1<<endl;
			}
			int l=0;
			int sum=0;
			int d=l,f=0;
			for(int i=1;i<=n;i++){
				sum+=c[i],m1;
				cout<<c[i].i1<<" "<<d<<endl;
				if(c[i].i1=d)
				{
					l++;
				}else
				{
					l=1;
					d++;
					}
					if(l>n/2){
						
						break;
					}
			}
			if(l>n/2){
				f=1;
				break;
			}
	}   
	if(f==0)
	{
		cout<<sum<<endl;
	}else
	{
		for(int i=1;i<=n;i++)
		{
			if(c[i].i1==d)
			{
				l++
			}else{
				l=1;
				d++;
			}
			if(l>n/2)
			{
				int f=0,h=0,ui=0;
				for(int j=1;j<=i;j++){
					if(c[j].i1==c[i].i1)
					{
						if(c[j].m2+c[j].m1+c[i].m2){
							f=1;
							h=(c[j].m2+c[i].m1)-(c[j].m1+c[i].m2);
							if(h>kl){
								kl=h;
								ui=j;
							}
						}
					}
					
				}
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
