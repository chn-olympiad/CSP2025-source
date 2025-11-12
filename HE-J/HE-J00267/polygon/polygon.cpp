#include<bits/stdc++.h>
using namespace std;
//排列组合 
//思路：
//通过深搜进行不同n个边的几何组合
//当组成的n个边的几何符合 sum>maxx_2*2时cnt++ 
int n;
int a[5010];
bool b[5010];
int cnt;//计算几何数量 
int maxx_1;//计算所选木棍最大的 
int sum;//计算所选木棍总和 
vector <int> c;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'&&ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
		
	}
	return x*f;
}
void dfs(int x,int ans_1){//x计量所选木棍要组合的n边形边数 
	if(ans_1==x){
		int sum_1=0;
		int maxx_2=0;
		for(int i=0;i<c.size();i++){
				if(c[i]>c[i+1]&&i!=c.size()-1){
					
					return ;
				}
				sum_1+=a[c[i]];
				maxx_2=max(maxx_2,a[c[i]]);
		}

		if(sum_1>maxx_2*2){
//			for(int i=0;i<c.size();i++){
//				cout<<a[c[i]]<<" ";
//			}
//					cout<<endl;
			cnt=(cnt+1)%998244353;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(c.size()!=0&&i<c[ans_1-1]){
			continue;
		}
		if(!b[i]){
			b[i]=1;
			c.push_back(i);
			dfs(x,ans_1+1);
			b[i]=0;
			c.pop_back();
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	if(n<3){
		cout<<0;
		return 0;
	}else if(n==3){
		for(int i=1;i<=3;i++){
			sum+=a[i];
			if(a[i]>maxx_1){
				maxx_1=a[i];
			}
		}
		if(sum>maxx_1*2){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	for(int i=3;i<=n;i++){
		dfs(i,0);
	} 
	cout<<cnt;
	
	return 0;
}
