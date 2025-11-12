#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,d,m;
}a[101010];
int n,t,b[10],s,ans;

bool cmp(node x,node y)
{
	return x.d<y.d;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	for(int j=1;j<=t;j++)
	 {
	 	vector<node> v[4];
	 	cin>>n; b[1]=b[2]=b[3]=0;
	 	ans=0;
	 	for(int i=1;i<=n;i++)
	 	 {
	 	 	cin>>a[i].a>>a[i].b>>a[i].c;
	 	 	if(a[i].a>a[i].b&&a[i].a>a[i].c)
	 	 	 {
	 	 	 	if(a[i].b>a[i].c)
	 	 	 	 {
	 	 	 	 	a[i].m=2;
	 	 	 	 	a[i].d=a[i].a-a[i].b;
					}
				else
				 {
				 	a[i].m=3;
	 	 	 	 	a[i].d=a[i].a-a[i].c;
				 }
	 	 	 	 b[1]++;
				v[1].push_back(a[i]); ans+=a[i].a;
			   }
			if(a[i].a<a[i].b&&a[i].b>a[i].c)
			 {
			 	if(a[i].a>a[i].c)
	 	 	 	 {
	 	 	 	 	a[i].m=1;
	 	 	 	 	a[i].d=a[i].b-a[i].a;
					}
				else
				 {
				 	a[i].m=3;
	 	 	 	 	a[i].d=a[i].b-a[i].c;
				 }
				 v[2].push_back(a[i]);
				b[2]++; ans+=a[i].b;
			 }
			if(a[i].c>a[i].b&&a[i].a<a[i].c)
			 {
			 	if(a[i].b>a[i].a)
	 	 	 	 {
	 	 	 	 	a[i].m=2;
	 	 	 	 	a[i].d=a[i].c-a[i].b;
					}
				else
				 {
				 	a[i].m=1;
	 	 	 	 	a[i].d=a[i].c-a[i].a;
				 }
				 v[3].push_back(a[i]);
				ans+=a[i].c; b[3]++;
			 }
		  }
		if(b[1]<=n/2&&b[2]<=n/2&&b[3]<=n/2) {cout<<ans<<"\n"; continue;}
		if(b[1]>n/2)
		 {
		 	sort(v[1].begin(),v[1].end(),cmp);
			for(int i=0;i<b[1]-n/2;i++)
		 	 {
		  		if(v[1][i].m==2)
		  		 {
		  		 	if(b[2]==n/2)
		  		 	 {
		  		 	 	b[3]++;
		  		 	 	ans-=v[1][i].a-v[1][i].c;
						}
		  		 	b[2]++;
		  		 	ans-=v[1][i].d;
				   }
				if(v[1][i].m==3)
		  		 {
		  		 	if(b[3]==n/2)
		  		 	 {
		  		 	 	b[2]++;
		  		 	 	ans-=v[1][i].a-v[1][i].b;
						}
		  		 	b[3]++;
		  		 	ans-=v[1][i].d;
				   }
			  }
		 }
		if(b[2]>n/2)
		 {
		 	sort(v[2].begin(),v[2].end(),cmp);
			for(int i=0;i<b[2]-n/2;i++)
		 	 {
		  		if(v[2][i].m==1)
		  		 {
		  		 	if(b[1]==n/2)
		  		 	 {
		  		 	 	b[3]++;
		  		 	 	ans-=v[2][i].b-v[2][i].c;
						}
		  		 	b[1]++;
		  		 	ans-=v[2][i].d;
				   }
				if(v[2][i].m==3)
		  		 {
		  		 	if(b[3]==n/2)
		  		 	 {
		  		 	 	b[1]++;
		  		 	 	ans-=v[2][i].b-v[2][i].a;
						}
		  		 	b[3]++;
		  		 	ans-=v[2][i].d;
				   }
			  }
		 }
		if(b[3]>n/2)
		 {
		 	sort(v[3].begin(),v[3].end(),cmp);
			for(int i=0;i<b[3]-n/2;i++)
		 	 {
		  		if(v[3][i].m==2)
		  		 {
		  		 	if(b[2]==n/2)
		  		 	 {
		  		 	 	b[1]++;
		  		 	 	ans-=v[3][i].c-v[3][i].a;
						}
		  		 	b[2]++;
		  		 	ans-=v[3][i].d;
				   }
				if(v[3][i].m==1)
		  		 {
		  		 	if(b[1]==n/2)
		  		 	 {
		  		 	 	b[2]++;
		  		 	 	ans-=v[3][i].c-v[3][i].b;
						}
		  		 	b[1]++;
		  		 	ans-=v[3][i].d;
				   }
			  }
		 }
		cout<<ans<<"\n";
	}
	return 0;
}
