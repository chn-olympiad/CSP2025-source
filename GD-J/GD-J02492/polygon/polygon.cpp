#include<bits/stdc++.h>
using namespace std;
//2^20 = 1048576
long long ans=0,mod=998244353;
int n,a[600];
bool b[1050000];
    //9:26,先写这一道题，dfs+状压+剪枝  40分
	//木棍数小于3 下一层
	// 
	//如果加入的小木棍比当前最长长度小
	//     |
	//     |----长度之和>max*2
	//     |        |
	//     |        |----ans++; dfs下一层
	//     |
	//     |----else dfs下一层 
	//
	// else max=i;
	//     |
	//     |----同上
	//     |
	//     |----同上 
string test10to2(int x){
	string s1="",s2="";
	while(x!=0){
		s1+=char(x%2+'0');
		s1+=s2;
		s2=s1;
		s1="";
		x/=2;
	}
	int lenttt=n-s2.size();
	while(lenttt){
		lenttt--;
		s1+='0';
	}
	s1+=s2;
	return s1;
}
void dfs(int i,int maxn,int sum,int x){//状态 最大值 和  已选择木棍的数量 	
	if(x>=n){
		return;
	}
	if(x<2){
		for(int j=0;j<n;j++){
			if((i&(1<<j))==0&&!b[(i|(1<<j))]){//位运算优先级！！！之前被坑惨了QwQ 
				b[(i|(1<<j))]=1;
				dfs((i|(1<<j)),max(maxn,a[j+1]),sum+a[j+1],x+1);
			}
		}
	}
	else{
		for(int j=0;j<n;j++){
			int v=(i|(1<<j));
			if((i&(1<<j))==0&&!b[v]){
				b[v]=1;
				if(a[j+1]<maxn){
					if(sum+a[j+1]>maxn*2){
						ans++;
					//	cout<<test10to2(v)<<"  1\n";
				//	cout<<1<<" "<<j+1<<"\n";
						ans%=mod;
					}
				//	cout<<test10to2(i)<<" to "<<test10to2(v)<<"\n";
					dfs(v,maxn,sum+a[j+1],x+1);
				}
				else{
					if(sum>a[j+1]){
						ans++;
				//		cout<<2<<" "<<j+1<<"\n";
						ans%=mod;
					}
				//	cout<<test10to2(i)<<" to "<<test10to2(v)<<"\n";
					dfs(v,a[j+1],sum+a[j+1],x+1);
				}
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	if(n<=3){
		int a1,a2,a3;
		cin>>a1>>a2>>a3;
		int sum=a1+a2+a3;
		int maxnn=max(a1,max(a2,a3));
		//dudududu max ver..
		//已经feng了 
		if(maxnn*2<sum){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
		//10：28 先把这题放一下 
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,0);
	cout<<ans%mod;
	//10:12 为什么会重复去相同的情况？ 
	return 0;
	//10：59 hahaha,I'm back!
	//精神状态良好 
	//11:24 YES!!!
	//应该有40了！！！
	//300分了！！  Y(>u<)Y
}
