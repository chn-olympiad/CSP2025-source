#include<bits/stdc++.h>
using namespace std;
const long long N=5010,mod=998244353;
int n,a[N];bool A=true;
void solve1(){	//+12pts
	if(a[1]+a[2]>a[3] && a[1]+a[3]>a[2] && a[2]+a[3]>a[1])cout<<1;
	else cout<<0;
}
long long Solve(int num,int now,int ma,int sum,int MA){	//已有元素数量，遍历到第几位，最大容积，长度总和，长度最大值
	long long res=0;
	if(num==ma){
		if(sum>2*MA)res++;
		return res;
	}
	for(int i=now;i<=n;i++){
		res+=Solve(num+1,i+1,ma,sum+a[i],max(MA,a[i]));
	}
	return res;
}
void solve2(){	//+28pts
	long long ans=0;
	for(int i=3;i<=n;i++){
		ans+=Solve(0,1,i,0,0);
	}
	cout<<ans%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)A=false;
	}
	
	//long long c=clock();
	
	if(n==3)solve1();
	if(n<=20)solve2();
	
	//cout<<'\n'<<"Time:"<<clock()-c<<"ms";
	
	return 0;
}
/*
CSP-J总结：
T1:number  100pts
T2:seat    100pts
T3:xor     (30+rand()%70)pts
T4:polygon 40pts
in all     [270+rand()%70]pts
I think it could get the one-so-on-award. 
*/

