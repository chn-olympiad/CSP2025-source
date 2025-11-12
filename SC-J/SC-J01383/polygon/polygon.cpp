#include<bits/stdc++.h>
#define int long long 
using namespace std;
int CCF[7891];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	int Lmax=0,sum=0;
	for(int i=1;i<=n;i++){
		cin>>CCF[i];
		sum+=CCF[i];
		Lmax=max(Lmax,CCF[i]);//实时获取木棍长度最大值 
	}
	if(sum>Lmax*2) cout<<1;
	else if(sum<=Lmax*2) cout<<0;
	else{
		while(1) cout<<"rp++ ";
	}
	return 0;
}
//试题册密码：上善若水 
//666这题暴力的话复杂度直接炸到O(n^n)了 
//死脑快想一下排列组合的知识 
//好像n=3只能合成1种三角形，爽吃12分 
//100+100+10+12=222我没救了 
//神圣的CCF大人给点分吧窝补药退役 
// ___          _       _   __     ___   _____    ___
//|   |        / \     | | / /    |   | / ___ \  |   |
// | |        / _ \    | |/ /      | |  | |  | |  | |
// | |       / /_\ \   |   /       | |  | |  | |  | |
// | |      / _____ \  |   \       | |  | |  | |  | |
// | |     / /     \ \ | |\ \      | |  | |__| |  | |
//|___|   /_/       \_\|_| \_\    |___| \_____/  |___|