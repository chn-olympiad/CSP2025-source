//rp++
#include<iostream>
//#include<windows.h>
#define int long long
using namespace std;
const int N=64;

int n;
int a[N];

int pop_cnt(int x){
	int ret=0;
	while(x){
		ret++;
		x&=x-1;
	}
	return ret;
}

bool check(int s){
	if(pop_cnt(s)<3){
		return false;
	}
	int maxs=0,sum=0;
	for(int i=1;i<=n;i++){
		if(s&(1<<i-1)){
			sum+=a[i];
			maxs=max(maxs,a[i]);
		}
	}
	return sum>2*maxs;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	#ifndef local
		freopen("polygon.in","r",stdin);
		freopen("polygon.out","w",stdout);
		//freopen("polygon.in","r",stdin);
		//freopen("polygon.out","w",stdout);
	#endif
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int s=0;s<(1<<n);s++){
		if(check(s)){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}

//祝各位选手好运！
//（试图上电视 
