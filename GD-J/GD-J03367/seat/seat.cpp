#include<bits/stdc++.h>
using namespace std;
const int N=100+5; 
int n,m,a[N],b[N],ans;
int lie,pm; //行、列、排名 

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m; //输入行和列 
	int x=1;
	int res=n*m;
	for(int i=1;i<=res;++i){
		cin>>a[i];
		ans=a[1]; //确定小R的成绩 
	}
	sort(a+1,a+res+1);//从小到大排序 
	for(int i=res;i>=0;--i){
		b[x]=a[i];//把成绩反过来再存一遍 
		x++;
	} 
	for(int i=1;i<=res;++i){
		if(b[i]==ans){
			pm=i;//找到小R的排名 
		}
	} 
	if(pm%n==1) lie=(pm+1)/n+1;//当蛇形座位到连接处时 判断为特殊情况 
	if(pm%n!=1) lie=(pm+1)/n;//普通情况 
	//直接确定行数两种情况的范围 
	if(lie%2==0){//（第一种）
		if(pm%n==1) cout<<lie<<" "<<n-(pm/n-1);
		if(pm%n==0) cout<<lie<<" "<<"1";
		if(pm%n!=1&&pm%n!=0) cout<<lie<<" "<<n-(pm/n);
	}
	if(lie%2!=0){//（第二种） 
		if(pm<=n) cout<<lie<<" "<<pm;
		if(pm>n) cout<<lie<<" "<<pm-(pm/(2*n))*(2*n);
	}
	return 0;
}
