#include<iostream>
#include<iomanip>
#include<string>
#include<cstdio>
#include<queue>
#include<vector>
#include<stack>
#include<math.h>
#include<algorithm>
#define ll long long
using namespace std;
const int N=1e5+5;
ll T,n;

stack<ll>la;
stack<ll>lb;
stack<ll>lc;
struct stua{
	ll ad;
	ll s;
}aa[N];
struct stub{
	ll ad;
	ll s;
}ab[N];
struct stuc{
	ll ad;
	ll s;
}ac[N];
bool cmpa(stua x,stua y){
	return x.s<y.s;
}
bool cmpb(stub x,stub y){
	return x.s<y.s;
}
bool cmpc(stuc x,stuc y){
	return x.s<y.s;
}
ll solve(ll n){
	bool check[N];
	while(!la.empty()) la.pop();
	while(!lb.empty()) lb.pop();
	while(!lc.empty()) lc.pop();
	ll sum=0;
	ll numa=0,numb=0,numc=0;
	for(int i=1;i<=n;i++){
		aa[i].ad=i;ab[i].ad=i;ac[i].ad=i;
		cin>>aa[i].s>>ab[i].s>>ac[i].s;
	}
	sort(aa+1,aa+n+1,cmpa);
	sort(ab+1,ab+n+1,cmpb);
	sort(ac+1,ac+n+1,cmpc);
	for(int i=1;i<=n;i++){
		la.push(i);
		lb.push(i);
		lc.push(i);
	}
	for(int i=1;i<=n;i++){
		
		while(!la.empty()&&(numa*2>=n||check[aa[la.top()].ad]==1)) la.pop();
		
		while(!lb.empty()&&(numb*2>=n||check[ab[lb.top()].ad]==1)) lb.pop();
		while(!lc.empty()&&(numc*2>=n||check[ac[lc.top()].ad]==1)) lc.pop();//清理
		
		if(la.empty()) la.push(0);if(lb.empty()) lb.push(0);if(lc.empty()) lc.push(0);
		
		if(aa[la.top()].s>=ab[lb.top()].s&&aa[la.top()].s>=ac[lc.top()].s){//aa最大 
			sum+=aa[la.top()].s;
			//cout<<aa[la.top()].s<<" "<<aa[la.top()].ad<<" "<<la.top()<<'\n';
			check[aa[la.top()].ad]=true;
			la.pop();
			numa++;
			continue;
		}
		if(aa[la.top()].s<=ab[lb.top()].s&&ab[lb.top()].s>=ac[lc.top()].s){//ab最大 
			sum+=ab[lb.top()].s;
			//cout<<ab[lb.top()].s<<" "<<ab[lb.top()].ad<<" "<<lb.top()<<'\n';
			check[ab[lb.top()].ad]=true;
			lb.pop();
			numb++;
			continue;
		}
		if(aa[la.top()].s<=ac[lc.top()].s&&ac[lc.top()].s>=ab[lb.top()].s){//ac最大 
			sum+=ac[lc.top()].s;
			//cout<<ac[lc.top()].s<<" "<<ac[lc.top()].ad<<" "<<lc.top()<<'\n';
			check[ac[lc.top()].ad]=true;
			lc.pop();
			numc++;
			continue;
		}
		
		
	}
	return sum;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;
	while(T--){
		cin>>n;
		cout<<solve(n)<<'\n';
	}
	
	
	fclose(stdin);fclose(stdout);
	
	return 0;
}
