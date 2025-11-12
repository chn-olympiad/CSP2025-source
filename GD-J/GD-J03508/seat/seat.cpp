#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,x,k,ans=1;
	cin>>n>>m;
	cin>>x;
	for(int i=2;i<=n*m;i++){
		cin>>k;
		if(k>x)ans++;
	}
	int a,b;
	a=ans/n + 1;
	b=ans%n;
	if(b==0){
		if(a%2==0){
			a--;
			b=n;
		}
		else{
			a--;b=1;
		}
	}
	else{
		if(a%2==0){
			b=n-b+1;
		}
	}
	cout<<a<<' '<<b;
	return 0;
} 
/*
CCF CSP-J/S 2025 RP++
当前题目：J T2
赛时预估：大约100pts 红~橙题 
版权所有 请勿翻录
陈彦羽
2025/11/1
惠州中学
*/ 
