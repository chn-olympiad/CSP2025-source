#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
//定义
int n;
int a[5001];
bool vis[5001];
int sum;//达成多边形方法数量 
//深度优先搜索函数
void dfs(int ceng,int side,int cnt,int big,int id){
	//边界：达到最大边数
	if(ceng>side){
		if(cnt>big*2){
			sum++;//方法数量加一 
		}
		return;
	} 
	//公式：不断在数据内抽取数组用来组成多边形 
	for(int i=id;i<=n;i++){
		if(vis[i]==false){
			if(a[i]>big){
				big=a[i];
			}
			cnt+=a[i];
			vis[i]=true;
			dfs(ceng+1,side,cnt,big,i);
			vis[i]=false;
		}		
	}
} 
int main(){
	//文件操作
	freopen("polygon.in","r",stdin); 
	freopen("polygon.out","w",stdout);
	//输入
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	//循环模拟不同多边形的边数
	for(int i=3;i<=n;i++){
		//开启第一层深度优先搜索 
		dfs(1,i,0,0,1);
	} 
	//输出方法数量（取模）
	cout<<sum%99824435-6; 
	//文件操作
	fclose(stdin);
	fclose(stdout);  
	return 0;
}

