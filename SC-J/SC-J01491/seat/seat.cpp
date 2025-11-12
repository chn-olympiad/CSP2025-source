#include<bits/stdc++.h>
using namespace std;
namespace solve{
	inline int read(){
		int x=0,f=1;char ch=getchar();
		while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
		while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
		return x*f;
	}
	int n,m;
	pair<int,int>a[105];
	int solve(){
		freopen("seat.in","r",stdin);
		freopen("seat.out","w",stdout);
		n=read();m=read();
		for(int i=1;i<=n*m;i++)
			a[i].first=read(),a[i].second=i;
		sort(a+1,a+n*m+1,greater<pair<int,int>>());
		int id=-1;
		for(int i=1;i<=n*m;i++)
			if(a[i].second==1){
				id=i;
				break;
			}
		int h,l;
		h=id%n;l=id/n+1;
		if(h==0)h=n,l--;
		if(!(l&1))h=n-h+1;
		cout<<l<<' '<<h<<endl;
		return 0;
	}
}
int main(){return solve::solve();}
/*
Microsoft Windows [版本 10.0.22000.318]
(c) Microsoft Corporation。保留所有权利。

D:\work>fc seat1.out seat1.ans
正在比较文件 seat1.out 和 SEAT1.ANS
FC: 找不到差异


D:\work>fc seat2.out seat2.ans
正在比较文件 seat2.out 和 SEAT2.ANS
FC: 找不到差异


D:\work>fc seat3.out seat3.ans
正在比较文件 seat3.out 和 SEAT3.ANS
FC: 找不到差异


D:\work>
*/