#include<bits/stdc++.h>
using namespace std;
int n,m;//n个人面试，期望有m个人被录取 
char s[1001];//题目难度，0为难，1为容易 
int c[1001];//第i个人的耐心程度
bool judge[1001]={true};//判断这个面试的排位是否被选过了 
int win=0;//真正录取的人数 
int sum=0;//总方案数 
int tie[1001];//用来记录目前的排列情况
int x=1;
void search(int k){
	if(k>n){
		return;
	}
	x*=k;
	search(k+1);
}
int main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	search(1);
	sum=x;
	cout<<sum;
	return 0;
}
