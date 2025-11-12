#include<iostream>
using namespace std;
const int maxn=500+5;
const long long mod=998244353;
int n,m;
string str;
int s[maxn],c[maxn];
long long f[maxn];
bool vis[maxn];//是否面试过 
long long dfs(int x,int cnt){//面试了x-1人，其中有cnt个人没过
	if(x-1-cnt==m)return f[n-x+1];//面试通过数量已达标 
	if(m-(x-1-cnt)>(n-x+1))return 0;//剩下的人不足以满足要求 
	//printf("dfs(%d,%d)\n",x,cnt); 
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			ans+=dfs(x+1,cnt+(cnt>=c[i]||s[x]==0));//注意下标是s[x] 
			ans%=mod;
			vis[i]=0;
		}
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	int s1=0;
	cin>>str;
	for(int i=1;i<=n;i++){
		s[i]=str[i-1]-'0';
		s1+=s[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	f[0]=1;
	for(int i=1;i<=n;i++)f[i]=(f[i-1]*i)%mod;
	if(s1==n){//特殊性质A
		printf("%lld",f[n]);
	}
	else if(s1<m)printf("0");//测试点15如果s1!=n,则没有人够入取
	else printf("%lld",dfs(1,0));
	return 0;
}
/*
in:
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
ans:
2204128
*/
