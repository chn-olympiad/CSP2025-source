#include<bits/stdc++.h>
#define TIMU (string)"polygon"
#define lli long long
using namespace std;
vector<int> mg(5005,0);
int n;
const lli mod = 998244353;
const static bool ts = 0;
void init(){
	cin>>n;
	for(int i = 0;i<n;i++) cin>>mg[i];
	sort(mg.begin(),mg.begin()+n);
	if(ts) for(int i = 0;i<n;i++) cout<<mg[i]<<endl;
	return;
}
/*
5
1 2 3 4 5
*/
lli dfs(int p = -1,int cntall = 0,int maxall = 0,int xznum = 0,vector<int> v = vector<int>(0)){
	// 已选择      总长度          最大长度        选择的数量 
	if(ts){
		for(int i = 0;i<xznum;i++) putchar(32),putchar(32),putchar(32),putchar(32);
		cout<<"dfs ";
		for(int i = 0;i<n-xznum;i++) putchar('-'),putchar(32),putchar('-'),putchar(32);
		printf("p=%4d cntall=%4d maxall=%4d xznum=%4d ",p,cntall,maxall,xznum);	
	}
	lli res=0;
	/*if(xznum>=3 && cntall<=(maxall*2)){
		if(ts)cout<<"CNT_F ";
		//return 0LL;
	}
	else */if(xznum<3 && cntall>(maxall*2)){
		res = 0;
		if(ts)cout<<"XZ_LO ";
	}
	else if(xznum>=3 && cntall>(maxall*2)){
		res = 1;
		if(ts)cout<<"XZ_OK ";
	}
	if(ts){
		for(int i : v){
			printf("%2d",i);
		}
		cout<<endl;	
	}
	for(int i = p+1;i<n;i++){
		vector<int> v1 = v;
		v1.push_back(i);
		res += dfs(i,cntall+mg[i],max(maxall,mg[i]),xznum+1,v1);
		res = res % mod;
	}
	return res;
}
int main(){
	freopen((TIMU+".in").c_str(),"r",stdin);freopen((TIMU+".out").c_str(),"w",stdout);//ios::sync_with_stdio(false);cin.tie(nullptr);
	init();
	lli r = dfs();
	cout<<r;
	return 0;
}
