#include <bits/stdc++.h>
using namespace std;
int n,m,k;
struct city{
	int c1;
	int c2;
	int p;
};
struct cts{
	int p1;
	int c1p;
	int c2p;
	int c3p;
	int c4p;
};
bool cmp(city a,city b){
	return a.p<b.p;
}
bool cmp1(cts a,cts b){
	return a.p1<b.p1;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	city a[m];
	for(int i=0;i<m;i++){
		cin>>a[i].c1>>a[i].c2>>a[i].p;
	}
	cts b[k];
	for(int i=0;i<k;i++){
		cin>>b[i].p1>>b[i].c1p>>b[i].c2p>>b[i].c3p>>b[i].c4p;
	}
	sort(a,a+m,cmp);
	sort(b,b+k,cmp1);
	int sum=0;
	for(int i=0;i<m/2;i++){
		sum+=a[i].p;
	}
	sum=sum+b[0].p1+b[0].c1p+b[0].c3p;
	cout<<sum;
	return 0;
}
