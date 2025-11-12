#include<bits/stdc++.h>
#define int long long
// 不知道怎么想的想到了平衡树 #include<bits/extc++.h> 
//using namespace __pbds_gnu;
using namespace std;
int read(){
	int x=0; bool opt=true; char c=getchar();
	while(!isdigit(c)){ if(c=='-')opt=false; c=getchar(); }
	while(isdigit(c)){ x=x*10+c-48; c=getchar(); }
	return opt?x:-x;
}
void write(int x){
	static int s[20]; int top=0;
	if(x<0)putchar('-'),x=-x;
	if(x==0){ putchar('0'); return; }
	while(x){ s[++top]=x%10; x/=10; }
	while(top>0){ putchar(s[top--]+48); }
}
const int _5k = 5005; // 5k黄金题目(不是暴戾语言) 
const int maxn = _5k;
int n;
int a[maxn];
int sum=0,maxx=-1,ans=0,tot=0;
void Dfs(int step=0){ // 2^n能过我吃
	if(step==n){ // 边界 
		if(tot==0)return;
		if(sum>(maxx<<1)){
			ans++;
			if(ans==998244353){
				ans=0;
			}
		}
		return;
	}
	int tmp=maxx;
	sum+=a[step]; maxx=max(maxx,a[step]); tot++;
	Dfs(step+1); // 取 
	sum-=a[step]; maxx=tmp; tot--;
	Dfs(step+1); // 不取 
} // 这还剪啥枝啊，能吗 
inline int C(int m,int n){ // 以m为底 n为... 
	if(m<n)cout<<"这么强势，m个你能选出比m还多的木棍";
	int ans=1;
	n=min(n,m-n);
	for(int i=m,j=1;j<=n;i--,j++){
		ans*=i;
		ans%=998244353;
	}
	for(int i=1;i<=n;i++){
		ans/=i;
	}
	return ans;
}
signed main(){
// 居然能用DFS拿(pian)分，大概能拿(pian)到40分 加上特殊性质(MaxLen==1)能再拿(骗)20 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	cout<<C(4,3)+C(4,4);
	n=read();
	if(n<3){
		cout<<0;
		return 0;
	}
	int same=-1; 
	for(int i=0;i<n;i++){
		a[i]=read();
		if(same==-1)same=a[i];
		else if(same!=a[i])same=-2;
	}
	if(same!=-2){ // 15~20的测试点 
//	cout<<"%%%orz\n";
		ans=0;
		for(int i=3;i<=n;i++){
//			cout<<n<<" "<<i<<'\n';
			ans+=C(n,i); 
		}
	}else{
		Dfs();
	}
	write(ans);
	return 0;
}
// 总的来说T1T2橙题  T3T4绿题(猜的)  难度比较正常(至少没有蓝题) 
