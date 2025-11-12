#include <bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,t;
long long f[N][3];
long long dp[N][3];
long long ans=0;
int comp(long long w1,long long w2,long long w3){
	if(w1>w2 && w1>w3) return 1;
	if(w2>w1 && w2>w3) return 2;
	else return 3;
}

struct node{
	int cnt0=n/2;
	int cnt1=n/2;
	int cnt2=n/2;
	long long w=0;
	
}s[5];
node x[5];

void dfs(int p,node s1,node s2,node s3){
	if(p==n+1){
		long long maxx=max(s1.w,s2.w);
		maxx=max(maxx,s3.w);
		ans=max(ans,maxx);
		return ;
	}
	//f[p][0]¶ÔÓ¦
	long long lp;
	long long w1=0,w2=0,w3=0;
	if(s1.cnt0-1>=0) w1=s1.w+f[p][0]; else w1=s1.w;
	if(s2.cnt0-1>=0) w2=s2.w+f[p][0]; else w2=s2.w;
	if(s3.cnt0-1>=0) w3=s3.w+f[p][0]; else w3=s3.w;
//	cout<<w1<<' '<<w2<<' '<<w3<<'\n';
	int num=comp(w1,w2,w3);
	if(num==1) lp=w1;
	else if(num==2) lp=w2;
	else lp=w3;
//	cout<<"lp:"<<' '<<lp<<'\n';
//	cout<<p<<' '<<lp<<'\n';
	x[1]={s[num].cnt0-1,s[num].cnt1,s[num].cnt2,lp};
	
	//f[p][1]
	w1=0,w2=0,w3=0;
	if(s1.cnt1-1>=0) w1=s1.w+f[p][1]; else w1=s1.w;
	if(s2.cnt1-1>=0) w2=s2.w+f[p][1]; else w2=s2.w;
	if(s3.cnt1-1>=0) w3=s3.w+f[p][1]; else w3=s3.w;
	num=comp(w1,w2,w3);
//	cout<<w1<<' '<<w2<<' '<<w3<<'\n';
	if(num==1) lp=w1;
	else if(num==2) lp=w2;
	else lp=w3;
//	cout<<"lp:"<<' '<<lp<<'\n';
	x[2]={s[num].cnt0,s[num].cnt1-1,s[num].cnt2,lp};
	
	//f[p][2]
	w1=0,w2=0,w3=0;
	if(s1.cnt2-1>=0) w1=s1.w+f[p][2]; else w1=s1.w;
	if(s2.cnt2-1>=0) w2=s2.w+f[p][2]; else w2=s2.w;
	if(s3.cnt2-1>=0) w3=s3.w+f[p][2]; else w3=s3.w;
	num=comp(w1,w2,w3);
//	cout<<w1<<' '<<w2<<' '<<w3<<'\n';
	if(num==1) lp=w1;
	else if(num==2) lp=w2;
	else lp=w3;
//	cout<<"lp:"<<' '<<lp<<'\n';
	x[3]={s[num].cnt0,s[num].cnt1,s[num].cnt2-1,lp};
	s[1]=x[1];
	s[2]=x[2];
	s[3]=x[3];
	for(int i=1;i<=3;i++){
//		cout<<"s"<<i<<' '<<s[i].cnt0<<' '<<s[i].cnt1<<' '<<s[i].cnt2<<' '<<s[i].w<<'\n';
	}
	dfs(p+1,s[1],s[2],s[3]);
}


int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=3;i++){
			s[i].cnt0=n/2;
			s[i].cnt1=n/2;
			s[i].cnt2=n/2;
			s[i].w=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=2;j++){
				cin>>f[i][j];
			}
		}
		dfs(1,s[1],s[2],s[3]);
		cout<<ans<<'\n';
	}
 } 
