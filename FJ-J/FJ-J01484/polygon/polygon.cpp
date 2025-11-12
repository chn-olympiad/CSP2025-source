#include<bits/stdc++.h>
using namespace std;
//目标：拿到 n<=20 -->40pts 如果T1T2 AC T3 30 T4 40 =270 希望吧 
//爆搜吧
//等等 n<=3 就是三角形 
//如果是连续区间可以直接上线段树 然而并不是 
const int MOD=998244353;
const int N=5010;
int n,a[N],sa[N],f[N],l[N],o[N];
int ans; 
map<string,int> mp;
void dfs(int id,int k,int p,int sum,int mx){
	//当前下标为id,目前取了k个数，目标p个数 取的数和为sum,最大值为mx
	//设置一个桶，如果当前序列的每一个数在桶里都有，那么去掉当前方案
	//将每一个方案排序后保存为字符串 ，用map映射标记 
	//数组o用来调试 
	l[k]=id;
	
	//f[id]=1;
	if(k==p){
		//有重复方案要去除 
		// 
		bool flag=0;
		for(int i=1;i<=k;i++) o[i]=l[i];
		sort(o+1,o+k+1);
		//sort(l+1,l+k+1);
		string s;
		for(int i=1;i<=k;i++){
			s+=('0'+o[i]);
		}	
		//cout<<"S:"<<s<<" f:"<<mp[s]<<'\n';			
		if(sum>mx*2 && mp[s]==0){
			ans++;//符合条件
			ans%=MOD;
			mp[s]=1;
//			cout<<"L:";
//			for(int i=1;i<=k;i++) cout<<l[i]<<" ";
			//cout<<'\n';
		} 
		return ;//计数 
	}

//
//	cout<<"L:";
//			for(int i=1;i<=k;i++) cout<<o[i]<<" ";
//			cout<<'\n';
	
	for(int i=1;i<=n;i++){
		if(i!=id && !f[i]){//小心卡死 
			f[i]=1;
			dfs(i,k+1,p,sum+a[i],max(mx,a[i]));
			f[i]=0;
		}
	} 
	
}

int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sa[i]=a[i];
	}
	
	sort(sa+1,sa+n+1);//排序 
	if(n<3){
		cout<<0;
		return 0;//数量都不够 
	}
	 
	if(n==3){//三根肯定都得取 直接三角形三边关系 12pts 
		int sum=a[1]+a[2]+a[3];//三边和 
		if(sum>sa[3]*2){
			cout<<1;
		}else cout<<0;
		return 0;
	}
	
	//从三角形枚举到n边形 对于每个n都爆搜 O(N!*N) 吧 能不能记忆化 
	for(int i=3;i<=n;i++){
		memset(f,0,sizeof(f));
		mp.clear();//清空 
		f[0]=1;//不能重复用 
		
		dfs(0,0,i,0,-1);
	}
	cout<<ans%MOD;
	return 0;
}
