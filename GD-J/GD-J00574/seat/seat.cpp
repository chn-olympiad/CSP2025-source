#include<bits/stdc++.h>
using namespace std;
//CSP-S RP++
int n,m,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;++i)
		scanf("%d",&a[i]);
	int s=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1,x(1),y(1);i<=n*m;++i){
		if(a[i]==s){
			printf("%d %d",y,x);
			return 0;
		}
		if(y&1){
			if(x==n)++y;
			else ++x;
		}
		else{
			if(x==1)++y;
			else --x;
		}
	}
	return 0;
}
/*
	是的没错，我在另外3道题的底下都写了一些莫名其妙的注释，就剩这题没写了 
	什么，你问我为什么要写这些？
	你说得对，但是《原神》是一款由上海米哈游公司自主研发的开放世界冒险游戏
	坏了，我又忘了...... 
*/
