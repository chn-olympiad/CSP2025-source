#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct dog{
	int c1,c2,c3;
}a[N];
/*
	dist1=1表示当前1组成员人数满 
	dist2=1表示当前2组成员人数满 
	dist3=1表示当前3组成员人数满 
	状态设计：dp[i][1]表示第i个同学去第1个部门的满意程度最大值
			  dp[i][2]表示第i个同学去第2个部门的满意程度最大值
			  dp[i][3]表示第i个同学去第3个部门的满意程度最大值
	
	初始状态：dp[1][1]=a[1].c1;
			  dp[1][2]=a[1].c2;
			  dp[1][3]=a[1].c3; 
	
	状态转移：if(!dist1) dp[i][1] = a[i].c1 + max(a[i-1][1],max(a[i-1][2],a[i-1][3]));
			  if(!dist2) dp[i][2] = a[i].c2 + max(a[i-1][1],max(a[i-1][2],a[i-1][3]));
			  if(!dist3) dp[i][3] = a[i].c3 + max(a[i-1][1],max(a[i-1][2],a[i-1][3]));
	 
	最终答案：max(dp[n][1],max(dp[n][2],dp[n][3])); 
*/ 
int dp[N][3],f[N],n,A=1,T=1,maxn[5],max1[5];
bool cmp(dog x,dog y){
	return x.c1>y.c1;
}
void te(){
	A=1,T=1;
	memset(maxn,0,sizeof(maxn));
	memset(max1,0,sizeof(max1));
	for(int i=1;i<=n;i++)
		if(a[i].c2 != 0 || a[i].c3 != 0) A=0;
	if(n==2){
		for(int i=1;i<=n;i++){
			maxn[i]=max(a[i].c1,max(a[i].c2,a[i].c3));
			if(a[i].c1>a[i].c2 && a[i].c1<a[i].c3 || a[i].c1<a[i].c2 && a[i].c1>a[i].c3) max1[i]=a[i].c1;
			if(a[i].c2<a[i].c1 && a[i].c2>a[i].c3 || a[i].c2>a[i].c1 && a[i].c2<a[i].c3) max1[i]=a[i].c2;
			if(a[i].c3<a[i].c1 && a[i].c3>a[i].c2 || a[i].c3>a[i].c1 && a[i].c3<a[i].c2) max1[i]=a[i].c3;
		}
		cout<<max(maxn[1]+max1[2],maxn[2]+max1[1]);
		T=0;
	}
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].c1>>a[i].c2>>a[i].c3;
	te();
	if(!T) return;
	if(A){
		long long ans;
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=a[i].c1;
		}
		cout<<ans<<endl;
		return;
	}
	memset(dp,0,sizeof(dp));
	bool dist1=false,dist2=false,dist3=false;
	dp[1][1]=a[1].c1;
	dp[1][2]=a[1].c2;
	dp[1][3]=a[1].c3;
	int s1=1,s2=1,s3=1;
	int p=max(a[1].c1,max(a[1].c2,a[1].c3));
	if(p>a[1].c1) s1=0;
	if(p>a[1].c2) s2=0;
	if(p>a[1].c3) s3=0;
	for(int i=2;i<=n;i++){
		dp[i][1] = (dist1 ? max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3])) : max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3])) + a[i].c1),s1++;
		dp[i][2] = (dist2 ? max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3])) : max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3])) + a[i].c2),s2++;
		dp[i][3] = (dist3 ? max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3])) : max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3])) + a[i].c3),s3++;
		f[i]=max(dp[i][1],max(dp[i][2],dp[i][3]));
		if(f[i]>dp[i][1]) s1--; 
		if(f[i]>dp[i][2]) s2--; 
		if(f[i]>dp[i][3]) s3--;
		if(s1==n/2) dist1=true;
		if(s2==n/2) dist2=true;
		if(s3==n/2) dist3=true;
	}
	//cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<endl;
	cout<<f[n]<<endl;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
