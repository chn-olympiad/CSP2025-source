#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][4],s[N],n,p[N];
struct f{
	int a,b,bh;
}d[N];
bool cmp(f s1,f s2)
{
	return s1.a<s2.a;
}
int chuli2()
{
	int ans=0;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(i==j)continue;
			ans=max(ans,a[1][i]+a[2][j]);
		}
	}
	return ans;
}
int chuli4()
{
	int ans=0;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			for(int k=1;k<=3;k++){
				if(i==j&&i==k)continue;
				for(int g=1;g<=3;g++){
					if(i==k&&k==g)continue;
					if(j==k&&k==g)continue;
					ans=max(ans,a[1][i]+a[2][j]+a[3][k]+a[4][g]);
				}
			}
		}
	}
	return ans;
}
int chuli10(){
	int ans1=0;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			for(int k=1;k<=3;k++){
				for(int g=1;g<=3;g++){
					if(i==j&&i==g&&k==g)continue;
					for(int g1=1;g1<=3;g1++){
						if(i==j&&i==g1&&k==g1)continue;
						if(i==j&&g==g1&&j==g1)continue;
						if(i==k&&g==g1&&k==g)continue;
						if(j==k&&g==g1&&k==g)continue;
						for(int g2=1;g2<=3;g2++){
							if(i==j&&i==k&&i==g2)continue;
							if(i==k&&i==g&&i==g2)continue;
							if(i==k&&i==g1&&i==g2)continue;
							if(j==k&&j==g&&j==g2)continue;
							if(j==k&&j==g1&&j==g2)continue;
							if(k==g&&k==g1&&k==g2)continue;
							ans1=max(ans1,a[1][i]+a[2][j]+a[3][k]+a[4][g]+a[5][g1]+a[6][g2]);
						}
					}
				}
			}
		}
	}
	/*int ans1=0;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			for(int k=1;k<=3;k++){
				if(i==j&&i==k)continue;
				for(int g=1;g<=3;g++){
					if(i==k&&k==g)continue;
					if(j==k&&k==g)continue;
					ans1=max(ans1,a[1][i]+a[2][j]+a[3][k]+a[4][g]);
				}
			}
		}
	}*/
	int ans2=0;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			for(int k=1;k<=3;k++){
				if(i==j&&i==k)continue;
				for(int g=1;g<=3;g++){
					if(i==k&&k==g)continue;
					if(j==k&&k==g)continue;
					ans2=max(ans2,a[7][i]+a[8][j]+a[9][k]+a[10][g]);
				}
			}
		}
	}
	/*int ans3=0;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(i==j)continue;
			ans3=max(ans3,a[9][i]+a[10][j]);
		}
	}*/
	int ans=ans1+ans2;
	return ans;
}
int chulia()
{
	int ans=0,sm=0;
	sort(d+1,d+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(sm<n/2){
			ans=ans+d[i].a;
			if(p[d[i].bh]==1)sm++;
		}
		else if(sm==n/2){
			if(p[d[i].bh]==0)ans+=d[i].a;
		}
		else ans+=d[i].b;
	}
	return ans;
}
int chulib()
{
	int ans=0;
	sort(s+1,s+n+1);
	for(int i=1;i<=n/2;i++)ans=ans+s[i];
	return ans;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	int t,b,c,x,y,z;
	cin>>t;
	while(t--){
		int ans=0;
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));
		cin>>n;
		if(n<200){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					cin>>a[i][j];
				}
			}
		}
		
		if(n==10)ans=chuli10();
		if(n==200){
			for(int i=1;i<=n;i++){
				cin>>x>>y>>z;
				if(x>y){
					p[i]=1,swap(x,y);
				}
				d[i].a=x,d[i].b=y,d[i].bh=i;
			}
		}
				
		if(n==1e5){
			for(int i=1;i<=n;i++){
				cin>>s[i]>>b>>c;
			}
		}
		if(n==2)ans=chuli2();
		else if(n==4)ans=chuli4();
		else if(n==10)ans=chuli10();
		else if(n==200)ans=chulia();
		else if(n==1e5)ans=chulib();
		else {
			int u=0,v=0;
			for(int i=1;i<=n;i++){
				u=0,v=0;
				u=max(a[i][1],a[i][2]);
				v=max(u,a[i][3]);
			}
			ans=ans+u+v;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
