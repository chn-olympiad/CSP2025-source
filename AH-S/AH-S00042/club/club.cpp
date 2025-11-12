
#include <bits/stdc++.h>

using namespace std;

const int maxn=201;
struct stu{
	int a,b,c,maxv,maxp=0;
};

int maxstuval(int a,int b,int c){
	return max(max(a,b),c);
}
int maxstup(int a,int b,int c){
	if(a>b && a>c){
		return 1;}
	else if(b>c && b>a)
		return 2;
	else 
		return 3;
}
void solve2(int n){
	stu s[100001];
	
	memset(s,0,sizeof(s));
	
	for(int i=1;i<=n;i++)
	{	
		int a,b,c;
		cin>>a>>b>>c;
		s[i]=stu{a,b,c,maxstuval(a,b,c),maxstup(a,b,c)};
		//s[i].maxp=maxstup(a,b,c);
		//printf("%d %d %d  %d %d\n", a,b,c,s[i].maxv,s[i].maxp);
	}
	
	sort(s+1,s+n+1,[](stu& a,stu& b){return a.maxv>b.maxv;});
	int num[4]={0,0,0};
	int ans=0;
	//int hasreset=0;
	for(int i=1;i<=n;i++)
	{	
		ans+=s[i].maxv;
		num[s[i].maxp]++;
		
		//printf("%d %d %d %d  \n", s[i].a,s[i].b,s[i].c,s[i].maxv);
		//printf("%d %d %d %d  %d %d\n", i, s[i].a,s[i].b,s[i].c,s[i].maxv,s[i].maxp);
	}
	
	int bud = maxstup(num[1], num[2], num[3]);
	int budmax = maxstuval(num[1], num[2], num[3]);
	//printf("%d %d \n", bud, budmax);
	vector<int> val;
	for(int i=1;i<=n;i++){
		if(s[i].maxp == bud){
			int cha=0;
			if(bud==1){
				 cha=min(s[i].a-s[i].b,s[i].a-s[i].c);
			}	
			if(bud==2){
				 cha=min(s[i].b-s[i].a,s[i].b-s[i].c);
			}	
			if(bud==3){
				 cha=min(s[i].c-s[i].a,s[i].c-s[i].b);
			}	
			val.push_back(cha);	
			//printf("%d\n",cha);
			//printf("%d %d %d %d  %d %d\n", i, s[i].a,s[i].b,s[i].c,s[i].maxv,s[i].maxp);
		}
	}
	
	sort(val.begin(),val.end());
	//for(auto& i:val){printf("%d\n",i);}
	int t=0;
	while(budmax>n/2){
		ans-=val[t];
		t++;
		budmax--;	
	}
	
	//printf("%d %d %d \n", num[1], num[2], num[3]);
	printf("%d\n",ans);
		//printf("\n");
}


int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    
	//<<"good1";
	
	int t;
	cin>>t;
	while(t--){
		int n;
		int a[maxn],b[maxn],c[maxn];
		int dp[100][100][100];
		memset(dp,0,sizeof(dp));
		int ans=0;
		cin>>n;
		if(n>100)solve2(n);
		else{
		for(int i=1;i<=n;i++)
		{cin>>a[i]>>b[i]>>c[i];}
		
		//cout<<a[1]<<b[1]<<"\n";
		for(int i=0;i<=n/2;i++)
		{
			for(int j=0;j<=n/2;j++)
			{
				for(int k=0;k<=n/2;k++)
				{
					if(i+j+k+1>n)continue;
					dp[i+1][j][k]=max(dp[i+1][j][k], dp[i][j][k]+a[i+j+k+1]);
					dp[i][j+1][k]=max(dp[i][j+1][k], dp[i][j][k]+b[i+j+k+1]);
					dp[i][j][k+1]=max(dp[i][j][k+1], dp[i][j][k]+c[i+j+k+1]);
					
				}
			}
		}
		
		for(int i=0;i<=n/2;i++)
		{
			for(int j=0;j<=n/2;j++)
			{
				for(int k=0;k<=n/2;k++)
				{
					ans=max(ans,dp[i][j][k]);
					//printf("%d %d %d %d\n", i,j,k,dp[i][j][k]);
					//cout<<i<<j<<k<<dp[i][j][k]);
				}
			}
		}
		cout<<ans<<"\n";}
	}
	
	


    return 0;
}
