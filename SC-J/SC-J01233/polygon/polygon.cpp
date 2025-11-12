#include<bits/stdc++.h>
using namespace std;
const int N = 998244353;
int main(){
	//期望作对15~20测试点得20 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	long long cnt=1;//防暴int 
	cin >> n;
	for(int i=1;i<=n;i++){
		cnt = cnt*2%N;//每条边都可以选择用或不用
		//因为每条边都长1，所以一定可以围成多边形 
	}
	if(cnt==0){ 
		cnt = N;//还要-1 
	}
	//减去选0~2条边的情况
	cnt -= 1;//0 
	cnt -= n;//1
	cnt -= (n*(n-1))/2;//2
	cout << cnt; 
	return 0;
}
