#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n;//refreshed
long long a[maxn][4];//refreshed
int stabgive[maxn];//refreshed
bool cchose[maxn];//huisu
int nmax;//unused
//可能的dp思路:前i個人分到j個組
long long dp58[202][202][202];
long long dp1011[202][202];
long long dfscnt;//debug
int stdin_status;
bool stabcmp(int as,int bs){
	////cerr<<as<<' '<<bs<<'\n';
	long long aval=a[as][1]-a[as][2];
	long long bval=a[bs][1]-a[bs][2];
	////cerr<<aval<<'_'<<bval<<'\n';
	return aval>bval;
}
/*void shuff(int *arr,int n){
	for (int i=1;i<=n;i++){
		srand(time());
		swap(a[i],a[rand()%n+1]);
	}
}*/
long long AB(){
	for (int i=1;i<=n;i++){
		stabgive[i]=i;
	}
	//shuff(stabgive,n);
	long long ans=0;
	sort(stabgive+1,stabgive+n+1,stabcmp);
	for (int i=1;i<=n;i++){
		if (i<=n/2)ans+=a[stabgive[i]][1];
		else ans+=a[stabgive[i]][2];
	}
	return ans;
}
long long dfshou(){
	int tmpm=0;
	long long ans=0;
	for (int i=1;i<=n;i++){
		if (!cchose[i]){
			stabgive[++tmpm]=i;
		}else{
			ans+=a[i][3];
			//cerr<<'*'<<i<<':'<<'c'<<'\n';
		}
	}
	sort(stabgive+1,stabgive+1+tmpm,stabcmp);
	int agive=0,bgive=0;
	for (int k=1;k<=tmpm;k++){
		int i=stabgive[k];
		if (a[i][1]>a[i][2]){
			if (agive<n/2){
				ans+=a[i][1];
				agive++;
				//cerr<<'*'<<i<<':'<<'a'<<'\n';
			}else{
				ans+=a[i][2];
				bgive++;
				//cerr<<'*'<<i<<':'<<'b'<<'\n';
			}
		}else if (a[i][1]<a[i][2]){
			if (bgive<n/2){
				ans+=a[i][2];
				bgive++;
				//cerr<<'*'<<i<<':'<<'b'<<'\n';
			}else{
				ans+=a[i][1];
				agive++;
				//cerr<<'*'<<i<<':'<<'a'<<'\n';
			}
		}else{
			if (agive<n/2){
				ans+=a[i][1];
				agive++;
				//cerr<<'*'<<i<<':'<<'a'<<'\n';
			}else{
				ans+=a[i][2];
				bgive++;
				//cerr<<'*'<<i<<':'<<'b'<<'\n';
			}
		}
	}
	return ans;
}
long long dfsbbl(int lst,int chs){
	dfscnt++;
	long long tas=0;
	if (lst>=n){
		return dfshou();
	}
	int now=lst+1;
	if (chs<(n/2) and (a[now][1]<=a[now][3] or a[now][2]<=a[now][3])){
		////cerr<<'!'<<'\n';
		cchose[lst+1]=1;
		tas=dfsbbl(lst+1,chs+1);
		cchose[lst+1]=0;
	}
	return max(dfsbbl(lst+1,chs),tas);
}
void banbaoli(){
	dfscnt=0;
	long long mns=AB();
	long long tas=dfsbbl(0,0);
	printf("%lld\n",max(tas,mns));
	cerr<<dfscnt<<endl;
}
void st58(){
	long long ans=0;
	for (int i=0;i<=n/2;i++){
		for (int j=0;j<=n/2;j++){
			for (int k=0;k<=n/2;k++){
				if (i+j+k>n or !(i or j or k) )continue;
				long long ato=(i==0?0:dp58[i-1][j][k]+a[i+j+k][1]);
				long long bto=(j==0?0:dp58[i][j-1][k]+a[i+j+k][2]);
				long long cto=(k==0?0:dp58[i][j][k-1]+a[i+j+k][3]);
				dp58[i][j][k]=max(ato,max(bto,cto));
				if (i+j+k==n){
					ans=max(ans,dp58[i][j][k]);
				}
			}
		}
	}
	printf("%lld\n",ans);
}
void st1011(){
	long long ans=0;
	for (int i=0;i<=n/2;i++){
		for (int j=0;j<=n/2;j++){
			for (int k=n/2;k>=0;k--){
				if (i+j+k>n or !(i or j or k) )continue;
				long long ato=(i==0?0:dp1011[j][k]+a[i+j+k][1]);
				long long bto=(j==0?0:dp1011[j-1][k]+a[i+j+k][2]);
				long long cto=(k==0?0:dp1011[j][k-1]+a[i+j+k][3]);
				dp1011[j][k]=max(ato,max(bto,cto));
				if (i+j+k==n){
					ans=max(ans,dp1011[j][k]);
				}
			}
		}
	}
	printf("%lld\n",ans);
}
void Q(){
	stdin_status=scanf("%d",&n);
	nmax=n/2;
	////cerr<<'*';
	long long maxa3=0;
	for (int i=1;i<=n;i++){
		stdin_status=scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		maxa3=max(maxa3,a[i][3]);
		////cerr<<maxa3<<'\n';
	}
	if (0){
		banbaoli();
	}else if (n<=200){
		st58();
	}
	else if (maxa3==0){
		printf("%lld\n",AB());
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	stdin_status=scanf("%d",&t);
	while(t--)Q();
	return 0;
}
/*
 A:5%
 B:15%
 Baoli:20%
 * 1 2
 * 3 4
 * 5 8
 * 9
 * 15 16
 * ab3

 */

