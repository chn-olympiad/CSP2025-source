//HD 
//map 
//当前遍历到 i
//用 a_i 更新 pre
//pre'=a_i^pre
//a_i^pre' 入 map 
//a_i^(a_i^pre)^(a_i^pre)=a_i
//查询是否有 k^pre
//有则ans++,mp.clear(),pre=0 
#include<bits/stdc++.h>
using namespace std;
int ans,n,k;
int a,pre;
map<int,int> mp;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a;
		pre^=a;
		mp[a^pre]++;
		if(mp[k^pre]!=0) ans++,pre=0,mp.clear();
	}
	cout<<ans<<endl;
}
//我要在这敲一个火车头！
/*
#include<iostream>
#include<cstdio>
#include<windows.h>
#include<vector>
#include<stuck>
#include<map>
#include<bits/stdc++.h>
#include<cmath>
#include<queue>
#include<priority_queue>
#include<set> 
*/ 
