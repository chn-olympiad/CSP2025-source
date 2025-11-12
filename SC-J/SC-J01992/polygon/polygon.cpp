#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[5001],s[5001];
int gs,ns=0,n;
void go(int i,int last){
	if(i==gs){
		int maxn=-1,ss=0;
		for(int j=0;j<=i-1;j++){
			maxn=max(maxn,s[j]);
			ss+=s[j];
		}
		if(ss>(2*maxn)){
			ns++;
			ns%=998244353;
		}
		return; 
	}
	for(int j=last+1;j<=n;j++){
		s[i]=a[j];
		go(i+1,j);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		gs=i;
		go(0,0);
	}
	cout<<ns; 
	return 0;
}
/*

枚举选几根小木棒
	枚举第i根小木棒的选择 
		选完后 判断是否可行 
*/