#include<bits/stdc++.h>
std::ifstream("polygon.in");
std::ofstream("polygon.out");
int n,a[5001],mod=998244353;long long cnt=0;
void number(int sum,int maxn,int chose,int i){
	if(chose>=3&&sum>=2*maxn){
		cnt++;
		cnt%=mod;
	}
	number(sum+a[i],a[i],chose+1,i++);
	number(sum,maxn,chose,i++);	
}
int main(){
	fin>>n;
	for(int i=1;i<=n;i++){
		fin>>a[i];
	}
	std::sort(a+1,a+n+1);
	number(0,0,0,1);
	fout<<cnt;
	return 0;
}
