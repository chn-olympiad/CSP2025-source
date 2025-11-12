#include<bits/stdc++.h>
using namespace std;
int n,t;
bool n1,n2;
struct node{
	int p1,p2,p3;
}a[1145140];
bool cmp(node a,node b){
	return a.p1 > b.p1;
}
void solve1(){
	sort(a + 1,a + n + 1,cmp);
	int s = 0;
	for(int i = 1;i <= n / 2;i++){
		s+=a[i].p1;
	}
	cout<<s<<endl;
}
void solve2(){
	int ep2 = a[1].p1 + a[2].p2,ep3 = a[1].p1 + a[2].p3;
	int fp1 = a[1].p2 + a[2].p1,fp3 = a[1].p2 + a[2].p3;
	int g1 = a[1].p3 + a[2].p1,g2 = a[1].p3 + a[2].p2;
	int maxn = max(ep2,ep3);
	int maxnn = max(fp1,fp3);
	int maxnnn = max(g1,g2);
	int ans = max(max(maxn,maxnn),maxnnn);
	cout<<ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 1;i <= n;i++){
			cin>>a[i].p1>>a[i].p2>>a[i].p3;
			if(a[i].p2 != 0) n1 = 1;
			if(a[i].p3 != 0) n2 = 1;
		} 
		if(n1 == 0 && n2 == 0){
			solve1();
			continue;
		}
		if(n == 2){
			solve2();
			continue;
		}
	}
	return 0;
}
/*
T1都没做出来
我的OI生涯画上了一个如此破碎的句号
（但至少我没有爆零） 
*/ 
