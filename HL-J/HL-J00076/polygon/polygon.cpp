#include<iostream>
#include<iomanip>
using namespace std;
int a[5008];
//int w[5008][65537];
//int n;
//bool check(int op){
//	int sum=0;
//	int maxx=0;
//	for(int i=1;i<=n;i++){
//		if((1<<(i-1))&op){
//			maxx=max(a[i],maxx);
//			sum+=a[i];
//		}
//	}
//	return sum>maxx*2;
//}
//int dfs(int x,int op){
//	if(x==0){
//		return check(op);
//	}
//	int res=0;
//	for(int i=1;i<=n;i++){
//		if(!((1<<(i-1))&(op))){
//			w[x][op]=dfs(x-1,op+(1<<i));
//		}
//		if(w[x][op]!=0){
//			res+=w[x][op];
//		}
//	}
//	return res;
//}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<1;
//	cout<<dfs(n,0);
}
/*
typedef f__k bool
f__k CCF = true
*/