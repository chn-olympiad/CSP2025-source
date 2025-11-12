/*
正在比较文件 seat3.ans 和 SEAT.OUT
FC: 找不到差异

模拟题， 

其实本题数据范围再放大一点也无妨，模拟而已，但是为啥不给大样例。

现在是 10:32

感觉没有去年难  ~（当然）~ 

去年的 D 题现在都还没写，不过去年的这个时候还是太糖了。

现在感觉良好，距离我的 2025OI 记，更近一步。

说实话感觉没啥写头，我现在看去年自己写的文章只想说：谁家小孩

不过写写归写写。但是这不是 XIXIFU 不给大样例的理由 X2

现在是 11:00 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=20;
int n,m,v[N*N],x;
inline bool cmp(int a,int b){
	return a>b;
}
int main (){
//	system("fc seat3.ans seat.out");
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>v[i];
	x=v[1];
	sort(v+1,v+n*m+1,cmp);
	int ax=0,ay=0,cnt=0;
	for(int j=1;j<=m;j++){
		if(j&1){
			for(int i=1;i<=n;i++){
				cnt++;
				if(v[cnt]==x){
					ax=i;ay=j;
				}
			}
		}
		else {
			for(int i=n;i>=1;i--){
				cnt++;
				if(v[cnt]==x){
					ax=i;ay=j;
				}
			}
		}
	}
	cout<<ay<<' '<<ax<<'\n';
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
