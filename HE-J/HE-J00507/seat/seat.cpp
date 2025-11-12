#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a<b;
}
//我来自偶然，像一颗尘土，有谁看出我的脆弱~~~~ 
int quyu(int aa,int nn){
	if(aa%nn!=0){
		return aa/nn+1;
	}else{
		return aa/nn;
	}
}
//判卷老师您玩宝可梦吗
//我其实是用梦话写的程序 
int pn(int aa,int nn,int n){
	if(aa%nn!=0){
		return aa%nn;
	}else{
		return n;
	}
	//51121511121
}
int m,n,a[550],p,m_a,n_a;
int main(){
	//斯普拉顿是世界上最好玩的游戏 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=m*n;i++){
		if(a[i]==p){
			p=i;
			break;
		}
	}
//做题不易，给个高分吧 
	m_a=quyu(p,n);
	n_a=pn(p,m,n);
	cout<<n_a<<" "<<m_a;
	return 0;
}
